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
using namespace std;
#define LL long long
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=60,INF=200000000;

char map[MAX][MAX];
int g[MAX*10][MAX*10],vis[MAX*10],y[MAX*10],grax[MAX][MAX],gray[MAX][MAX];
int n,m,cou;

void getg()
{
    mem(grax,0);
    mem(gray,0);
    int i,j,k;
    for(k=i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j]=='*'){
                k++;
                for(;map[i][j]=='*';j++)
                    grax[i][j]=k;
            }
        }
    }
    cou=Max(cou,k);
    for(k=j=0;j<m;j++){
        for(i=0;i<n;i++){
            if(map[i][j]=='*'){
                k++;
                for(;map[i][j]=='*';i++)
                    gray[i][j]=k;
            }
        }
    }
    cou=Max(cou,k);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(grax[i][j] && gray[i][j])
                g[grax[i][j]][gray[i][j]]=1;
        }
    }
}

int dfs(int u)
{
    int v;
    for(v=1;v<=cou;v++){
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
 //  freopen("in.txt","r",stdin);
    int i,j,ans;
    while(~scanf("%d%d",&n,&m))
    {
        ans=cou=0;
        mem(y,0);
        mem(g,0);
        for(i=0;i<n;i++){
            scanf("%s",map[i]);
        }

        getg();
        for(i=1;i<=cou;i++){
            mem(vis,0);
            if(dfs(i))ans++;
        }

        printf("%d\n",ans);
    }
}