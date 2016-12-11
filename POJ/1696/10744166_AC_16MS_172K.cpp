#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
#define LL __int64
const int MAX=60,INF=200000000;
struct Node{
	int num,x,y;
}nod[MAX];
struct Line{
	int x1,y1,x2,y2;
}line[MAX];
double length(Node &a);
int dir(Line &a,Node &b);
int las(Line &a,Line &b);
double jiao(Line &a,Node &b);
int xj(Line &a);
int vis[MAX];
int T,n,k;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,ok,minw,miny,cou,ans[MAX],maxw;
	double maxd,t;
	Line l;
	scanf("%d",&T);
	while(T--)
	{
		cou=0;
		k=-1;
		miny=INF;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&nod[i].num,&nod[i].x,&nod[i].y);
			if(nod[i].y<miny){
				miny=nod[i].y;
				minw=i;
			}
		}
		line[++k].x1=0,line[k].y1=miny;
		line[k].x2=nod[minw].x,line[k].y2=miny;
		vis[minw]=1;
		ans[cou++]=nod[minw].num;
		while(1){
			ok=0;
			maxd=-2;
			for(i=1;i<=n;i++){
				if(!vis[i] && dir(line[k],nod[i])){
					t=jiao(line[k],nod[i]);
					l.x1=line[k].x2;
					l.y1=line[k].y2;
					l.x2=nod[i].x;
					l.y2=nod[i].y;
					if(t>maxd && !xj(l)){
						maxd=t;
						maxw=i;
						ok=1;
					}
				}
			}
			if(ok){
				++k;
				line[k].x1=line[k-1].x2;
				line[k].y1=line[k-1].y2;
				line[k].x2=nod[maxw].x;
				line[k].y2=nod[maxw].y;
				ans[cou++]=nod[maxw].num;
				vis[maxw]=1;
			}
			else break;
		}

		printf("%d",cou);
		for(i=0;i<cou;i++)
			printf(" %d",ans[i]);
		putchar('\n');
	}
	return 0;
}

int xj(Line &a)
{
	int i;
	for(i=0;i<=k;i++)
		if(las(line[i],a) && las(a,line[i]))
			return 1;
	return 0;
}

double length(Node &a)
{
	return sqrt((double)(a.x*a.x+a.y*a.y));
}
int dir(Line &a,Node &b)
{
	int t;
	Node t1,t2;
	t1.x=a.x2-a.x1;
	t1.y=a.y2-a.y1;
	t2.x=b.x-a.x2;
	t2.y=b.y-a.y2;
	t=t1.x*t2.y-t2.x*t1.y;
	if(t>=0)return 1;
	return 0;
}

double jiao(Line &a,Node &b)
{	
	Node t1,t2;
	t1.x=a.x2-a.x1;
	t1.y=a.y2-a.y1;
	t2.x=b.x-a.x2;
	t2.y=b.y-a.y2;
	return (double)(t1.x*t2.x+t1.y*t2.y)/( length(t1)*length(t2) );
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