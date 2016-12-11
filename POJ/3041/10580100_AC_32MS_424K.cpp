#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#define LL __int64
const int MAX=510,INF=1000000000;
int DFS(int u);
bool g[MAX][MAX];
int vis[MAX],y[MAX],ok[MAX];
int n,m;
int main()
{	
//	freopen("in.txt","r",stdin);
	int i,a,b,ans;
	while(~scanf("%d%d",&n,&m))
	{
		memset(g,0,sizeof(g));
		memset(ok,0,sizeof(ok));
		memset(y,-1,sizeof(y));
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			g[a-1][b-1]=1;
		}

		for(i=ans=0;i<n;i++){
			memset(vis,0,sizeof(vis));
			if(DFS(i))ans++;
			else ok[i]=1;
		}

		printf("%d\n",ans);
	}
	return 0;
}

int DFS(int u)
{
	if(ok[u])return 1;
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