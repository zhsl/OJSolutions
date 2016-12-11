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
const int MAX=210,INF=0x3f3f3f3f;

struct Edge{
    int from,to,cap,flow;
};

vector<Edge> edge;
vector<int> g[MAX];
int d[MAX],cur[MAX],vis[MAX];
int n,m,s,t;

int bfs()
{
    int x,i;
    queue<int> q;
    q.push(s);
    mem(vis,0);
    d[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        x=q.front();q.pop();
        for(i=0;i<g[x].size();i++){
            Edge& e=edge[g[x][i]];
            if(!vis[e.to] && e.cap>e.flow){
                vis[e.to]=1;
                d[e.to]=d[x]+1;
                q.push(e.to);
            }
        }
    }
    return vis[t];
}

int dfs(int x,int a)
{
    if(x==t || a==0)return a;
    int f,flow=0;
    for(int& i=cur[x];i<g[x].size();i++){
        Edge& e=edge[g[x][i]];
        if(d[x]+1==d[e.to] && (f=dfs(e.to,Min(a,e.cap-e.flow)))>0){
            e.flow+=f;
            edge[g[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(!a)break;
        }
    }
    return flow;
}

int dinic()
{
    int flow=0;
    while(bfs()){
        mem(cur,0);
        flow+=dfs(s,INF);
    }
    return flow;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,u,v,val,ans;
    while(~scanf("%d%d",&m,&n))
    {
        s=1,t=n;
        for(i=1;i<=n;i++)g[i].clear();
        edge.clear();
        m<<=1;
        for(i=0;i<m;i+=2){
            scanf("%d%d%d",&u,&v,&val);
            edge.push_back((Edge){u,v,val,0});
            edge.push_back((Edge){v,u,0,0});
            g[u].push_back(i);
            g[v].push_back(i+1);
        }

        ans=dinic();

        printf("%d\n",ans);
    }
    return 0;
}