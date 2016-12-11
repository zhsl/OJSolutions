#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
const int MAX=1510,INF=200000010,MOD=7;
const double esp=1e-3,DNF=1e8;
int min(int x,int y){return x<y?x:y;};
int dfs(int u);
int u[MAX*10],v[MAX*10],dp[MAX][2],vis[MAX],first[MAX],next[MAX*10];
int n;
int main()
{
//	freopen("in.txt","r",stdin);
	int x,y,m,k;
	while(~scanf("%d",&n))
	{
		memset(first,-1,sizeof(first));
		memset(vis,0,sizeof(vis));
		k=0;
		while(n--){
			scanf("%d:(%d)",&x,&m);
			while(m--){
				scanf("%d",&y);
				u[k]=x,v[k]=y;
				next[k]=first[x];
				first[x]=k++;
				u[k]=y,v[k]=x;
				next[k]=first[y];
				first[y]=k++;
			}
		}

		dfs(0);

		printf("%d\n",dp[0][0]<dp[0][1]?dp[0][0]:dp[0][1]);
	}
	return 0;
}

int dfs(int u)
{
	int y;
	vis[u]=1;
	dp[u][0]=0;
	dp[u][1]=1;
	for(y=first[u];y!=-1;y=next[y]){
		if(!vis[v[y]]){
			dfs(v[y]);
			dp[u][0]+=dp[v[y]][1];
			dp[u][1]+=min(dp[v[y]][0],dp[v[y]][1]);
		}
	}
	return 1;
}