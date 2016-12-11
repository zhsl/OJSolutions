#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
const int MAX=110,INF=200000000;
const double esp=1e-6;
double max(double x,double y){return x>y?x:y;}
double min(double x,double y){return x<y?x:y;}
struct Node{
	double x,y;
};
struct Line{
	double x1,y1,x2,y2;
}line[2];
int quick(Line &a,Line &b);
int las(Line &a,Line &b);
void format(Line &a,double &A,double &B,double &C);
void geto(Node &o);
void getk(Line &a,Line &b,Node &o);
void getr2(Line &a,Node &b,Node &o);
double getline(Line &a);
double dir(Line &a);
double chaji(Line &a,Line &b);
double getarea(Node *a,int all);
Node nod[3];
int T,k;
double a1,b1,c1,a2,b2,c2;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	double ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
			&line[0].x1,&line[0].y1,&line[0].x2,&line[0].y2,
			&line[1].x1,&line[1].y1,&line[1].x2,&line[1].y2);

		if(quick(line[0],line[1]) && las(line[0],line[1]) && las(line[1],line[0])){
			if(line[0].y1!=line[0].y2 && line[1].y1!=line[1].y2
				 && chaji(line[0],line[1])!=0){
				format(line[0],a1,b1,c1);
				format(line[1],a2,b2,c2);
				geto(nod[0]);
				getk(line[0],line[1],nod[1]);
				if( ( dir(line[0])*dir(line[1])<=0 )
					|| ( dir(line[0])>0 && ( fabs(dir(line[k]))>fabs(dir(line[!k]))
					|| fabs(nod[1].x-nod[0].x)>getline(line[!k]) ) )
					|| ( dir(line[0])<0 && ( fabs(dir(line[k]))>fabs(dir(line[!k]))
					|| fabs(nod[1].x-nod[0].x)>getline(line[!k]) ) ) ){
					getr2(line[!k],nod[1],nod[2]);
					ans=getarea(nod,3);
				}
			}
		}

		printf("%.2lf\n",fabs(ans/2));
	}
	return 0;
}

double dir(Line &a)
{
	return (a.y1-a.y2)/(a.x1-a.x2);
}

double getline(Line &a)
{
	double x;
	x=a.y1==max(a.y1,a.y2)?a.x1:a.x2;
	return fabs(x-nod[0].x);
}

double chaji(Line &a,Line &b)
{
	Node r1,r2;
	r1.x=a.x1-a.x2;
	r1.y=a.y1-a.y2;
	r2.x=b.x1-b.x2;
	r2.y=b.y1-b.y2;
	return r1.x*r2.y-r2.x*r1.y;
}

void format(Line &a,double &A,double &B,double &C)
{
	A=a.y2-a.y1;
	B=a.x1-a.x2;
	C=-A*a.x1-B*a.y1;
}

void geto(Node &o)
{
	o.x=(c2*b1-c1*b2)/(a1*b2-a2*b1);
	o.y=(c2*a1-c1*a2)/(b1*a2-b2*a1);
}

void getk(Line &a,Line &b,Node &o)
{
	double maxy[2];
	maxy[0]=max(line[0].y1,line[0].y2);
	maxy[1]=max(line[1].y1,line[1].y2);
	k=maxy[0]<=maxy[1]?0:1;
	o.x=line[k].y1==maxy[k]?line[k].x1:line[k].x2;
	o.y=maxy[k];
}

void getr2(Line &a,Node &b,Node &o)
{
	Line r1;
	if(a.y1<a.y2){
		o.x=a.x1,o.y=a.y1;
		a.x1=a.x2,a.y1=a.y2;
		a.x2=o.x,a.y2=o.y;
	}
	r1.x1=nod[1].x,r1.y1=nod[1].y;
	r1.x2=nod[1].x-1,r1.y2=nod[1].y;
	format(r1,a1,b1,c1);
	format(a,a2,b2,c2);
	geto(o);
}

double getarea(Node *a,int all)
{
	int i;
	double s=0;
	all--;
	for(i=0;i<all;i++)
		s+=a[i].x*a[i+1].y-a[i+1].x*a[i].y;
	s+=a[i].x*a[0].y-a[0].x*a[i].y;
	return s;
}

int quick(Line &a,Line &b)  //快速排斥,可能相交return 1;
{
	if(min(a.x1,a.x2)>max(b.x1,b.x2)
		|| min(a.y1,a.y2)>max(b.y1,b.y2)
		|| max(a.x1,a.x2)<min(b.x1,b.x2)
		|| max(a.y1,a.y2)<min(b.y1,b.y2))
		return 0;
	return 1;
}

int las(Line &a,Line &b)  //跨立实验,跨立return 1;
{
	Node r1,r0,r2;
	r1.x=a.x1-b.x1;
	r1.y=a.y1-b.y1;
	r0.x=b.x2-b.x1;
	r0.y=b.y2-b.y1;
	r2.x=a.x2-b.x1;
	r2.y=a.y2-b.y1;
	if( ((r1.x*r0.y)-(r0.x*r1.y))
		*((r2.x*r0.y)-(r0.x*r2.y))<=0 )return 1;
	else return 0;
}