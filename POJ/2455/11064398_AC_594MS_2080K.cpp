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
    int u,v,c,f,len;
}e[MAX*MAX*2];

int d[MAX],cur[MAX];
int first[MAX],next[MAX*MAX*2];
int n,m,T,maxlen,minlen,hav,lim;

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
            if(e[i].len<=lim && e[i].c>0 && !d[e[i].v]){
                d[e[i].v]=d[x]+1;
                q.push(e[i].v);
            }
        }
    }
    return d[t];
}

int dfs(int x,int a)
{
    if(x==n)return a;
    int t,f,flow=0;
    for(int& i=cur[x];i!=-1;i=next[i]){
        t=Min(a,e[i].c);
        if(e[i].len<=lim && t && d[x]+1==d[e[i].v] && (f=dfs(e[i].v,t))){
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
    int i;
    hav=0;
    lim=limit;
    while(bfs(s,t)){
        for(i=1;i<=n;i++)cur[i]=first[i];
        hav+=dfs(s,INF);
    }
    return hav;
}

int binary()
{
    int i,t,low=minlen,mid,high=maxlen;
    while(low<high){
        for(i=0;i<m;i++){
            e[i].c=1;
            e[i].f=0;
        }
        mid=(low+high)>>1;
        t=dinic(1,n,mid);
        if(t<T)low=mid+1;
        else high=mid;
    }
    return low;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,a,b,val,ans;
    while(~scanf("%d%d%d",&n,&m,&T))
    {
        mem(first,-1);
        maxlen=-INF;minlen=INF;
        m<<=1;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&val);
            if(val>maxlen)maxlen=val;
            if(val<minlen)minlen=val;
            e[i].u=a;e[i].v=b;
            e[i].len=val;
            next[i]=first[a];first[a]=i;
            i++;
            e[i].u=b;e[i].v=a;
            e[i].len=val;
            next[i]=first[b],first[b]=i;
        }

        ans=binary();

        printf("%d\n",ans);
    }
    return 0;
}
