#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
const int MAX=510,INF=200000010,MOD=7;
const double esp=1e-3,DNF=1e8;
int cmp(const void *a,const void *b){
	return *(int*)b - *(int*)a;
}
struct Node{
	int x,y;
}nod[MAX];
int dis(Node &a,Node &b){
	int x,y;
	x=a.x-b.x;
	y=a.y-b.y;
	return x*x+y*y;
}
void prim();
int w[MAX][MAX],d[MAX],vis[MAX];
int T,s,p;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		memset(w,0,sizeof(w));
		scanf("%d%d",&s,&p);
		for(i=0;i<p;i++)
			scanf("%d%d",&nod[i].x,&nod[i].y);
		for(i=0;i<p-1;i++)
			for(j=i+1;j<p;j++)
				w[i][j]=w[j][i]=dis(nod[i],nod[j]);

		prim();
		qsort(d,p,sizeof(int),cmp);
		s--;
		for(i=0;i<s;i++);
		
		printf("%.2lf\n",sqrt((double)d[i]));
	}
	return 0;
}

void prim()
{
	int i,x,y,m;
	memset(vis,0,sizeof(vis));
	for(i=0;i<p;i++)d[i]=INF;
	d[0]=0;
	for(i=0;i<p;i++){
		m=INF;
		for(y=0;y<p;y++)
			if(!vis[y] && d[y]<m)m=d[x=y];
		vis[x]=1;
		for(y=0;y<p;y++){
			if(w[x][y] && w[x][y]<d[y] && !vis[y])
				d[y]=w[x][y];
		}
	}
	return;
}