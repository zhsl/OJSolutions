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
const int MAX=510,INF=0x3f3f3f3f;

int g[MAX][MAX],y[MAX],vis[MAX];
int n,m;

int dfs(int u)
{
    int v;
    for(v=1;v<=n;v++){
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
    int i,j,k,ans,a,b;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        ans=0;
        mem(y,0);
        mem(g,0);
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            g[a][b]=1;
        }
        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++)
                    g[i][j]=((g[i][k]&&g[k][j]) || g[i][j]);
            }
        }

        for(i=1;i<=n;i++){
            mem(vis,0);
            if(dfs(i))ans++;
        }

        printf("%d\n",n-ans);
    }
    return 0;
}