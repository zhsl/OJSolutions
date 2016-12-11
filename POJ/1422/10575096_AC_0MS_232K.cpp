#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#define LL __int64
const int MAX=130,INF=1000000000;
int DFS(int u);
int vis[MAX],y[MAX],g[MAX][MAX];
int T,k,n,m;
int main()
{	
//	freopen("in.txt","r",stdin);
	int i,a,b,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(y,-1,sizeof(y));
		memset(g,0,sizeof(g));
		scanf("%d%d",&n,&k);
		for(i=0;i<k;i++){
			scanf("%d%d",&a,&b);
			g[a-1][b-1]=1;
		}

		for(i=0;i<n;i++){
			memset(vis,0,sizeof(vis));
			if(DFS(i))ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}

int DFS(int u)
{
	int i;
	for(i=0;i<n;i++)
		if(g[u][i] && !vis[i]){
			vis[i]=1;
			if(y[i]==-1 || DFS(y[i])){
				y[i]=u;
				return 1;
			}
		}
	return 0;
}