#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=110,INF=1000010,MOD=7;
const double esp=1e-8,DNF=1e8;
int dij(int s,int end);
int w[MAX][MAX],vis[MAX],d[MAX];
int n,A,B;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,a,k,ans;
	while(~scanf("%d%d%d",&n,&A,&B))
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				w[i][j]=INF;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			for(j=0;j<k;j++){
				scanf("%d",&a);
				w[i][a]=j?1:0;
			}
		}

		ans=dij(A,B);

		printf("%d\n",ans==INF?-1:ans);
	}
	return 0;
}

int dij(int s,int end)
{
	int i,x,y,m,t;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)d[i]=INF;
	d[s]=0;
	for(i=0;i<n;i++){
		m=INF;
		for(y=1;y<=n;y++)
			if(!vis[y] && d[y]<m)m=d[x=y];
		vis[x]=1;
		for(y=1;y<=n;y++){
			t=d[x]+w[x][y];
			if(t<d[y])
				d[y]=t;
		}
	}
	return d[end];
}