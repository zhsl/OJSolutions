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

const int MAX=1010,INF=200000000;
struct Node{
    int d,u;
};
struct Edge{
    int from,to,dis;
};

int n,m,S,T,K;
int d[MAX],vis[MAX];
vector<Edge> edge1,edge2;
vector<int> G1[MAX],G2[MAX];

struct cmp1{
    bool operator()(const Node &a,const Node &b){
        return a.d>b.d;
    }
};
struct cmp2{
    bool operator()(const Node &a,const Node &b){
        return a.d+d[a.u]>b.d+d[a.u];
    }
};

void init(int n){
    edge1.clear();
    edge2.clear();
    for(int i=1;i<=n;i++)
        G1[i].clear();
    for(int i=1;i<=n;i++)
        G2[i].clear();
}

void dijkstra(int s,vector<Edge>& edge){
    int i,u;
    priority_queue<Node,vector<Node>,cmp1> q;
    for(i=1;i<=n;i++)d[i]=INF;d[s]=0;
    mem(vis,0);
    q.push((Node){0,s});
    while(!q.empty()){
        u=q.top().u;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(i=0;i<G2[u].size();i++){
            Edge& e=edge[G2[u][i]];
            if(d[u]+e.dis<d[e.to]){
                d[e.to]=d[u]+e.dis;
                q.push((Node){d[e.to],e.to});
            }
        }
    }
}

int astar(int s,int t,int k,vector<Edge>& edge){
    int i;
    int cou[MAX];
    mem(cou,0);
    Node nod;
    priority_queue<Node,vector<Node>,cmp2> q;
    q.push((Node){d[s],s});
    if(s==t)k++;
    while(1){
        nod=q.top();q.pop();
        if(nod.u==t)cou[nod.u]++;
        if(cou[nod.u]==k)return nod.d;
        for(i=0;i<G1[nod.u].size();i++){
            Edge& e=edge[G1[nod.u][i]];
            q.push((Node){nod.d-d[nod.u]+d[e.to]+e.dis,e.to});
        }
    }
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int i,ans,u,v,dis;
    while(~scanf("%d%d",&n,&m)){
        init(n);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&dis);
            G1[u].push_back(i);
            edge1.push_back((Edge){u,v,dis});
            G2[v].push_back(i);
            edge2.push_back((Edge){v,u,dis});
        }
        scanf("%d%d%d",&S,&T,&K);
        if(m){
            dijkstra(T,edge2);
            if(d[S]!=INF)
                printf("%d\n",astar(S,T,K,edge1));
            else printf("-1\n");
        }
        else printf("-1\n");
    }
    return 0;
}