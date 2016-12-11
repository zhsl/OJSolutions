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
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=1010,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Edge{
    int u,v,w;
}e[N*10*2];
int first[N],next[N*10*2],d[N],cou[N],cou2[N];
int T,s,f,n,m,mt;

void adde(int a,int b,int c)
{
    e[mt].u=a,e[mt].v=b;e[mt].w=c;
    next[mt]=first[a],first[a]=mt++;
    e[mt].u=b,e[mt].v=a;e[mt].w=c;
    next[mt]=first[b],first[b]=mt++;
}

int dijkstra(int s)
{
    int i,u;
    pii t;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    mem(d,0x3f);d[s]=0;
    cou[s]=1;
    q.push(make_pair(d[s],s));
    while(!q.empty()){
        t=q.top();q.pop();
        u=t.second;
        if(t.first!=d[u])continue;
        for(i=first[u];i!=-1;i=next[i]){
            if((i&1)==0)continue;
            if(d[u]+e[i].w<d[e[i].v]){
                cou[e[i].v]=cou[u];
                d[e[i].v]=d[u]+e[i].w;
                q.push(make_pair(d[e[i].v],e[i].v));
            }
            else if(d[u]+e[i].w==d[e[i].v])cou[e[i].v]+=cou[u];
        }
    }
    return 1;
}

int dfs(int u)
{
    if(cou2[u]!=-1)return cou2[u];
    cou2[u]=0;
    int i;
    for(i=first[u];i!=-1;i=next[i]){
        if(i&1)continue;
        if(d[u]-e[i].w==d[e[i].v])
            cou2[u]+=dfs(e[i].v);
        else if(d[u]-e[i].w+1==d[e[i].v])
            cou2[u]+=cou[e[i].v];
    }
    return cou2[u];
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,c,ans;
    scanf("%d",&T);
    while(T--)
    {
        mt=0;
        mem(first,-1);
        mem(cou2,-1);
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            adde(a,b,c);
        }
        scanf("%d%d",&s,&f);

        dijkstra(f);
        ans=cou[s];
        ans+=dfs(s);

        printf("%d\n",ans);
    }
    return 0;
}