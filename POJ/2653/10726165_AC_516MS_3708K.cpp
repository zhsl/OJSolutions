#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
const int MAX=100010,INF=200000010,MOD=7;
const double esp=1e-3,DNF=1e8;
struct Node{
	double x,y;
};
struct Line{
	double x1,y1,x2,y2;
}line[MAX];
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
int quick(Line &a,Line &b);
int las(Line &a,Line &b);
int vis[MAX];
int n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,flag;
	while(scanf("%d",&n) && n)
	{
		k=1;
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);

		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(quick(line[i],line[j])
					&& las(line[i],line[j]) && las(line[j],line[i]) ){
					vis[i]=1;
					break;
				}
			}
		}

		printf("Top sticks: ");
		for(i=flag=0;i<n;i++){
			if(!vis[i]){
				if(flag)printf(", %d",i+1);
				else{flag=1;printf("%d",i+1);}
			}
		}
		printf(".\n");
	}
	return 0;
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