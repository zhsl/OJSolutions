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
#define pii pair<LL,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=50010,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Edge{
    int u,v,w;
}e[2*N];
int first[N],next[2*N],p[N],w[N];
int T,n,m,mt;
LL ans,d[N];

void adde(int a,int b,int c)
{
    e[mt].u=a,e[mt].v=b;e[mt].w=c;
    next[mt]=first[a],first[a]=mt++;
    e[mt].u=b,e[mt].v=a;e[mt].w=c;
    next[mt]=first[b],first[b]=mt++;
}

int dijkstra(int s)
{
    int i,u,cou=0;
    pii t;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    mem(d,0x3f);d[s]=0;
    q.push(make_pair(d[s],s));
    while(!q.empty()){
        t=q.top();q.pop();
        u=t.second;
        if(t.first!=d[u])continue;
        cou++;
        for(i=first[u];i!=-1;i=next[i]){
            if(d[u]+e[i].w<d[e[i].v]){
                d[e[i].v]=d[u]+e[i].w;
                p[e[i].v]=i;
                q.push(make_pair(d[e[i].v],e[i].v));
            }
        }
    }
    return cou;
}

LL dfs(int u)
{
    int i;
    LL sum=w[u],t;
    for(i=first[u];i!=-1;i=next[i]){
        if(p[e[i].v]==i){
            sum+=t=dfs(e[i].v);
            ans+=e[i].w*t;
        }
    }
    return sum;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        ans=mt=0;
        mem(first,-1);
        mem(p,-1);
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",w+i);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            adde(a,b,c);
        }

        if(dijkstra(1)==n || n==0){dfs(1);printf("%I64d\n",ans);}
        else printf("No Answer\n");
    }
    return 0;
}