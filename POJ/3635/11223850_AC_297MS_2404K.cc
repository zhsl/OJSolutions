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
const int N=1010,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Node{
    int d,u,c;
    bool operator < (const Node &ths) const {
        return d>ths.d;
    }
};
struct Edge{
    int u,v,w;
}e[N*20];
int vis[N][110],d[N][110],w[N],first[N],next[N*20];
int n,m,t,mt,cup;

void adde(int a,int b,int c)
{
    e[mt].u=a,e[mt].v=b,e[mt].w=c;
    next[mt]=first[a],first[a]=mt++;
    e[mt].u=b,e[mt].v=a,e[mt].w=c;
    next[mt]=first[b],first[b]=mt++;
}

int Dijkstra(int s,int end)
{
    int i,j,k,dis,u,v,c;
    Node t;
    priority_queue<Node> q;
    mem(vis,0);
    mem(d,INF);
    d[s][0]=0;
    q.push(Node{0,s,0});
    while(!q.empty()){
        t=q.top();q.pop();
        u=t.u;c=t.c;
        if(u==end)return t.d;
        if(vis[u][c])continue;
        vis[u][c]=1;
        if(c<cup && t.d+w[u]<d[u][c+1]){
            d[u][c+1]=t.d+w[u];
            q.push(Node{d[u][c+1],u,c+1});
        }
        for(i=first[u];i!=-1;i=next[i]){
            v=e[i].v;
            if(c>=e[i].w && d[u][c]<d[v][c-e[i].w]){
                d[v][c-e[i].w]=d[u][c];
                q.push(Node{d[u][c],v,c-e[i].w});
            }
        }
    }
    return -1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,c,ans;
    while(~scanf("%d%d",&n,&m))
    {
        mt=0;
        mem(first,-1);
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            adde(a,b,c);
        }
        scanf("%d",&t);
        while(t--){
            scanf("%d%d%d",&cup,&a,&b);
            ans=Dijkstra(a,b);
            if(ans!=-1)printf("%d\n",ans);
            else printf("impossible\n");
        }
    }
    return 0;
}