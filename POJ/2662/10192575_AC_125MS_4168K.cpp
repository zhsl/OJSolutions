#include<stdio.h>
#include<string.h>
const int MAX=1010,INF=0x7fffffff;
int DFS(int v);
int w[MAX][MAX],n,m,d[MAX],vis[MAX],dp[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,y,t;
	while(scanf("%d%d",&n,&m) && n)
	{
		memset(w,0,sizeof(w));
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));

		for(i=1;i<=m;i++){
			int a;
			scanf("%d%d%d",&x,&y,&a);
			w[x][y]=w[y][x]=a;
		}

		for(i=0;i<=n;i++)d[i]=INF;
		d[2]=0;
		for(i=0;i<n;i++){
			int m=INF;
			for(y=1;y<=n;y++)if(!vis[y] && d[y]<=m)m=d[x=y];
			vis[x]=1;
			for(y=1;y<=n;y++){
				if(w[x][y]){
			    	t=d[x]+w[x][y];
			    	if(t<d[y])
				    	d[y]=t;
				}
			}
		}

		printf("%d\n",DFS(1));
	}
	return 0;
}

int DFS(int x)
{
	if(dp[x])return dp[x];
	if(x==2){return 1;}
	for(int i=1;i<=n;i++){
		if(w[i][x] && d[i]<d[x]){
			dp[x]+=DFS(i);
		}
	}
	return dp[x];
}