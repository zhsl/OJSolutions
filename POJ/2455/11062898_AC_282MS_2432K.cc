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
    int u,v,c;
}e[MAX*MAX*2];

struct List{
    int a,b,len;
}l[MAX*MAX];

int d[MAX],cur[MAX];
int first[MAX],next[MAX*MAX*2];
int n,m,k,maxlen,minlen,mm;

void addedge(int u,int v)
{
    e[mm].u=u;e[mm].v=v;
    e[mm].c=1;
    next[mm]=first[u],first[u]=mm++;
    e[mm].u=v;e[mm].v=u;
    e[mm].c=1;
    next[mm]=first[v],first[v]=mm++;
}

int bfs(int s,int t)
{
    int x,i;
    queue<int> q;
    mem(d,0);
    d[s]=1;
    q.push(s);
    while(!q.empty()){
        x=q.front();q.pop();
        for(i=first[x];i!=-1;i=next[i]){
            if(e[i].c>0 && !d[e[i].v]){
                d[e[i].v]=d[x]+1;
                q.push(e[i].v);
            }
        }
    }
    return d[t];
}

int dfs(int x,int a)
{
    if(x==n || a==0)return a;
    int t,f,flow=0;
    for(int& i=cur[x];i!=-1;i=next[i]){
        if(d[x]+1==d[e[i].v] && (f=dfs(e[i].v,Min(a,e[i].c)))>0){
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            a-=f;
            if(!a)break;
        }
    }
    return flow;
}

int dinic(int s,int t,int limit)
{
    int i,ret=0;
    while(bfs(s,t)){
        for(i=1;i<=n;i++)cur[i]=first[i];
        ret+=dfs(s,INF);
    }
    return ret;
}

int binary()
{
    int i,t,low=1,mid,high=maxlen;
    while(low<high){
        mid=(low+high)>>1;
        mem(first,-1);
        for(i=mm=0;i<m;i++)
            if(l[i].len<=mid)
                addedge(l[i].a,l[i].b);
        t=dinic(1,n,mid);
        if(t<k)low=mid+1;
        else high=mid;
    }
    return low;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        maxlen=-INF;minlen=INF;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].len);
            if(l[i].len>maxlen)maxlen=l[i].len;
            if(l[i].len<minlen)minlen=l[i].len;
        }

        printf("%d\n",binary());
    }
    return 0;
}