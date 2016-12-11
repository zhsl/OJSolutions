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

struct Node{
    int d,u,flag;
    bool operator < (const Node &oth) const{
        return d>oth.d;
    }
};
struct Edge{
    int u,v,w;
}e[N*10];
int first[N],next[N*10],d[N][2],cou[N][2];
int T,s,f,n,m,mt;

void adde(int a,int b,int c)
{
    e[mt].u=a,e[mt].v=b;e[mt].w=c;
    next[mt]=first[a],first[a]=mt++;
}

int dijkstra(int s)
{
    int i,u,v,w,k,dis;
    Node t;
    priority_queue<Node> q;
    mem(d,0x3f);d[s][0]=d[s][1]=0;
    cou[s][0]=cou[s][1]=1;
    t.d=0,t.u=s,t.flag=0;
    q.push(t);
    while(!q.empty()){
        t=q.top();q.pop();
        u=t.u;dis=t.d;k=t.flag;
        if(dis!=d[u][k])continue;
        for(i=first[u];i!=-1;i=next[i]){
            v=e[i].v;w=e[i].w;
            if(dis+w<d[v][0]){
                cou[v][1]=cou[v][0];
                cou[v][0]=cou[u][0];
                d[v][1]=d[v][0];
                d[v][0]=dis+w;
                q.push(Node{d[v][0],v,0});
                q.push(Node{d[v][1],v,1});
            }
            else if(dis+w==d[v][0])cou[v][0]+=cou[u][0];
            else if(dis+w<d[v][1]){
                d[v][1]=dis+w;
                cou[v][1]=cou[u][k];
                q.push(Node{d[v][1],v,1});
            }
            else if(dis+w==d[v][1])cou[v][1]+=cou[u][k];
        }
    }
    return cou[f][0]+(d[f][1]==d[f][0]+1?cou[f][1]:0);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        mt=0;
        mem(first,-1);
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            adde(a,b,c);
        }
        scanf("%d%d",&s,&f);

        printf("%d\n",dijkstra(s));
    }
    return 0;
}