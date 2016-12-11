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
#define pdi pair<double,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=110,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Edge{
    int u,v,w;
}e[N*N];
int p[N],vis[N],mst[N][N],d[N][N],w[N][N];
int T,n,m,mt;

int cmp(const Edge& a,const Edge& b)
{
    return a.w<b.w;
}

int find(int x){return p[x]==x?x:p[x]=find(p[x]);}

int dfs(int& s,int u,int max)
{
    int v;
    for(v=1;v<=n;v++){
        if(mst[u][v] && !vis[v]){
            vis[v]=1;
            d[s][v]=Max(max,w[u][v]);
            dfs(s,v,d[s][v]);
        }
    }
    return 0;
}

int Kruskal()
{
    int i,j,x,y,sum=0;
    for(i=1;i<=n;i++)p[i]=i;
    sort(e,e+m,cmp);
    mem(mst,0);
    for(i=0;i<m;i++){
        x=find(e[i].u);
        y=find(e[i].v);
        if(x!=y){
            sum+=e[i].w;
            p[y]=x;
            mst[e[i].u][e[i].v]=mst[e[i].v][e[i].u]=1;
        }
    }
    return sum;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,a,b,c,ok,ans;
    scanf("%d",&T);
    while(T--)
    {
        mt=0;
        mem(w,-1);
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            w[a][b]=w[b][a]=c;
            e[i].u=a,e[i].v=b,e[i].w=c;
        }

        ans=Kruskal();
        for(i=1;i<=n;i++){
            mem(vis,0);vis[i]=1;
            dfs(i,i,0);
        }
        for(i=0,ok=1;i<m;i++)
            if(d[e[i].u][e[i].v]==e[i].w &&
               !mst[e[i].u][e[i].v]){ok=0;break;}

        if(ok)printf("%d\n",ans);
        else printf("Not Unique!\n");
    }
    return 0;
}