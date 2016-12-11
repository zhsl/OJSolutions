#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
#define LL __int64
const int MAX=310,INF=200000000;
int DFS(int x);
int vis[MAX],y[MAX],w[110][MAX];
int T,n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,ok,t;
	scanf("%d",&T);
	while(T--)
	{
		memset(w,0,sizeof(w));
		memset(y,-1,sizeof(y));
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++){
			scanf("%d",&k);
			for(j=0;j<k;j++){
				scanf("%d",&t);
				t--;
				w[i][t]=1;
			}
		}

		for(i=0,ok=1;i<m;i++){
			memset(vis,0,sizeof(vis));
			if(!DFS(i)){
				ok=0;
				break;
			}
		}
		
		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}

int DFS(int x)
{
	int i;
	if(!vis[x]){
		vis[x]=1;
		for(i=0;i<n;i++){
			if(w[x][i]){
				if(y[i]==-1 || DFS(y[i])){
					y[i]=x;
					return 1;
				}
			}
		}
	}
	return 0;
}