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
#define LL __int64
#define pdi pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=160,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

struct Node{
    int u,v;
}nod[N];

int f[N][N],first[N],next[N];
int n,m;

void dfs(int u)
{
    f[u][0]=1;
    f[u][1]=0;
    if(first[u]==-1)return;
    int i,j,k,v,t;
    for(i=first[u];i!=-1;i=next[i]){
        v=nod[i].v;
        dfs(v);
        for(j=m;j>0;j--){
            t=INF;
            for(k=1;k<=j;k++)
                t=Min(t,f[v][j-k]+f[u][k]);
            f[u][j]=t;
        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    while(~scanf("%d%d",&n,&m))
    {
        ans=INF;
        mem(f,INF);
        mem(first,-1);
        for(i=1,j=0;i<n;i++){
            scanf("%d%d",&nod[i].u,&nod[i].v);
            next[j]=first[nod[i].u];
            first[nod[i].u]=j++;
        }

        dfs(1);
        for(i=1;i<=n;i++)
            ans=Min(ans,f[i][m]);

        printf("%d\n",ans);
    }
    return 0;
}