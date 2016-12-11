#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define LL long long
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=110,INF=0x3f3f3f3f;

int g[MAX][MAX],y[MAX],vis[MAX];
int n,m,k;

int dfs(int u)
{
    int v;
    for(v=1;v<=m;v++){
        if(g[u][v] && !vis[v]){
            vis[v]=1;
            if(!y[v] || dfs(y[v])){
                y[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,ans,a,b,t;
    while(~scanf("%d",&n) && n)
    {
        ans=0;
        mem(y,0);
        mem(g,0);
        scanf("%d%d",&m,&k);
        for(i=0;i<k;i++){
            scanf("%d%d%d",&t,&a,&b);
            g[a][b]=1;
        }

        for(i=1;i<=n;i++){
            mem(vis,0);
            if(dfs(i))ans++;
        }

        printf("%d\n",ans);
    }
    return 0;
}