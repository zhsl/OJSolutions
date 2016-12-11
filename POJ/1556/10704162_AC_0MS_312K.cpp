#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=100,INF=1000,MOD=7;
const double esp=1e-8,DNF=1e8;
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
struct Line{
	double x1,y1,x2,y2;
}line[MAX][MAX];
struct Node{
	double x,y;
}nod[MAX];
int quick(Line &a,Line &b);
int las(Line &a,Line &b);
double dijkstra(int s,int end);
double dis(Node &a,Node &b);
int n,k;
double w[MAX][MAX],d[MAX],vis[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,p,q,ok;
	double ans;
	Line l;
	int s,end;
	while(~scanf("%d",&n) && ~n)
	{
		for(i=0,k=1;i<n;i++){
			scanf("%lf",&line[i][0].x1);
			line[i][0].y1=0;
			line[i][2].y2=10;
			for(j=0;j<3;j++)
				line[i][j].x1=line[i][j].x2=line[i][0].x1;
			scanf("%lf",&line[i][0].y2);
			nod[k].x=line[i][0].x1;
			nod[k++].y=line[i][0].y2;
			scanf("%lf%lf",&line[i][1].y1,&line[i][1].y2);
			nod[k].x=line[i][0].x1;
			nod[k++].y=line[i][1].y1;
			nod[k].x=line[i][0].x1;
			nod[k++].y=line[i][1].y2;
			scanf("%lf",&line[i][2].y1);
			nod[k].x=line[i][0].x1;
			nod[k++].y=line[i][2].y1;
		}
		nod[0].x=0,nod[0].y=5;
		nod[k].x=10,nod[k++].y=5;
		for(i=0;i<k;i++)
	    	for(j=0;j<k;j++)
		    	w[i][j]=DNF;
		for(i=0;i<k-1;i++){
			for(j=i+1;j<k;j++){
				l.x1=nod[i].x,l.y1=nod[i].y;
				l.x2=nod[j].x,l.y2=nod[j].y;
				if(l.x1!=l.x2){
					ok=1;
					for(s=0;s<n && line[s][0].x1<=l.x1;s++);
					for(end=n-1;end>=0 && line[end][0].x1>=l.x2;end--);
					for(p=s;p<=end;p++){
						for(q=0;q<3;q++){
							if(quick(line[p][q],l) && las(line[p][q],l) && las(l,line[p][q])){
								ok=0;break;
							}
						}
						if(!ok)break;
					}
				}
				else ok=0;
				if(ok)w[i][j]=w[j][i]=dis(nod[i],nod[j]);
			}
		}

		ans=w[k-2][k-1]==10?10:dijkstra(0,k-1);
		printf("%.2lf\n",ans);
	}
    return 0;
}

double dijkstra(int s,int end)
{
	int i,x,y;
	double t,m;
	memset(vis,0,sizeof(vis));
	for(y=0;y<k;y++)d[y]=DNF;
	d[s]=0;
	for(i=0;i<k;i++){
		m=DNF;
		for(y=0;y<k;y++)
			if(!vis[y] && d[y]<m)m=d[x=y];
		vis[x]=1;
		for(y=0;y<k;y++){
			t=d[x]+w[x][y];
			if(t<d[y])d[y]=t;
		}
	}
	return d[end];
}

double dis(Node &a,Node &b)
{
	double x=a.x-b.x,y=a.y-b.y;
	return sqrt(x*x+y*y);
}

int quick(Line &a,Line &b)
{
	if(min(a.x1,a.x2)>max(b.x1,b.x2)
		|| min(a.y1,a.y2)>max(b.y1,b.y2)
		|| max(a.x1,a.x2)<min(b.x1,b.x2)
		|| max(a.y1,a.y2)<min(b.y1,b.y2))
		return 0;
	return 1;
}

int las(Line &a,Line &b)
{
	Node r1,r0,r2;
	r1.x=a.x1-b.x1;
	r1.y=a.y1-b.y1;
	r0.x=b.x2-b.x1;
	r0.y=b.y2-b.y1;
	r2.x=a.x2-b.x1;
	r2.y=a.y2-b.y1;
	if( ((r1.x*r0.y)-(r0.x*r1.y))
		*((r2.x*r0.y)-(r0.x*r2.y))<0 )return 1;
	else return 0;
}