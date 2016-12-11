#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=110,INF=1000,MOD=7;
const double esp=1e-8;
struct Line{
	double x1,y1,x2,y2;
}line[MAX];
int can(Line &a,Line &b);
int slove(Line &a);
double dis(Line &a);
int T,n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,ok,k;
	Line t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);

		if(n>2){
			for(i=0;i<n-1;i++){
				for(k=0;k<2;k++){
					if(k)t.x1=line[i].x1,t.y1=line[i].y1;
					else t.x1=line[i].x2,t.y1=line[i].y2;
					for(j=i+1,ok=0;j<n;j++){
						t.x2=line[j].x1,t.y2=line[j].y1;
						if(dis(t)>=esp && slove(t)){
							ok=1;
							break;
						}
						t.x2=line[j].x2,t.y2=line[j].y2;
						if(dis(t)>=esp && slove(t)){
							ok=1;
							break;
						}
					}
					if(ok)break;
				}
				if(ok)break;
			}
		}
		else ok=1;

		printf("%s\n",ok?"Yes!":"No!");
	}
    return 0;
}

double dis(Line &a)
{
	double x,y;
	x=a.x1-a.x2;
	y=a.y1-a.y2;
	return sqrt(x*x+y*y);
}

int slove(Line &a)
{
	int i,ok=1;
	for(i=0;i<n;i++){
		if(!can(line[i],a)){
			ok=0;break;
		}
	}
	return ok;
}

int can(Line &a,Line &b)
{
	double r1[2],r0[2],r2[2];
	r1[0]=a.x1-b.x1;
	r1[1]=a.y1-b.y1;
	r0[0]=b.x2-b.x1;
	r0[1]=b.y2-b.y1;
	r2[0]=a.x2-b.x1;
	r2[1]=a.y2-b.y1;
	if( ((r1[0]*r0[1])-(r0[0]*r1[1]))
		*((r2[0]*r0[1])-(r0[0]*r2[1]))<=0)return 1;
	else return 0;
}
