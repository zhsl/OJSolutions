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
const int MAX=35,INF=0x3f3f3f3f;

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int w[MAX*MAX>>1][MAX*MAX>>1],g[MAX][MAX],y[MAX*MAX],vis[MAX*MAX];
int n,m,k,coux,couy;

void getg()
{
    int i,j,flag=0,k,ni,nj;
    mem(w,0);
    for(i=0;i<n;i++)
        for(j=flag^=1;j<m;j+=2)
            if(g[i][j]!=-1)g[i][j]=++couy;
    flag=1;
    for(i=0;i<n;i++){
        for(j=flag^=1;j<m;j+=2){
            if(g[i][j]!=-1){
                ++coux;
                for(k=0;k<4;k++){
                    ni=i+dx[k],nj=j+dy[k];
                    if(ni>=0&&ni<n && nj>=0&&nj<m && g[ni][nj]!=-1){
                        w[coux][g[ni][nj]]=1;
                    }
                }
            }
        }
    }
}

int dfs(int u)
{
    int v;
    for(v=1;v<=couy;v++){
        if(w[u][v] && !vis[v]){
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
  //  freopen("in.txt","r",stdin);
    int i,j,a,b,ok;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        mem(g,0);
        mem(y,0);
        coux=couy=0;
        ok=1;
        for(i=0;i<k;i++){
            scanf("%d%d",&a,&b);
            g[b-1][a-1]=-1;
        }

        if(!(k&1)){
            getg();
            if(coux==couy){
                for(i=1;i<=coux;i++){
                    mem(vis,0);
                    if(!dfs(i)){
                        ok=0;
                        break;
                    }
                }
            }
            else ok=0;
        }
        else ok=0;

        printf("%s\n",ok?"YES":"NO");
    }
    return 0;
}