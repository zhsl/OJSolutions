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
const int MAX=20010,INF=0x3f3f3f3f;

struct Edge{
    int u,v,cap;
}e[MAX*30];

int first[MAX],next[MAX*30],d[MAX],cur[MAX],fa[MAX],num[MAX];
int n,m,s,t,mm;

void adde1(int a,int b,int val)
{
    e[mm].u=a;e[mm].v=b;
    e[mm].cap=val;
    next[mm]=first[a];first[a]=mm++;
    e[mm].u=b;e[mm].v=a;
    e[mm].cap=0;
    next[mm]=first[b];first[b]=mm++;
}

void adde2(int a,int b,int val)
{
    e[mm].u=a;e[mm].v=b;
    e[mm].cap=val;
    next[mm]=first[a];first[a]=mm++;
    e[mm].u=b;e[mm].v=a;
    e[mm].cap=val;
    next[mm]=first[b];first[b]=mm++;
}

void bfs()
{
    int x,i,j;
    queue<int> q;
    mem(d,-1);
    q.push(t);
    d[t]=0;
    while(!q.empty()){
        x=q.front();q.pop();
        for(i=first[x];i!=-1;i=next[i]){
            if(d[e[i].v]<0){
                d[e[i].v]=d[x]+1;
                q.push(e[i].v);
            }
        }
    }
}

int augment()
{
    int x=t,a=INF;
    while(x!=s){
        a=Min(a,e[fa[x]].cap);
        x=e[fa[x]].u;
    }
    x=t;
    while(x!=s){
        e[fa[x]].cap-=a;
        e[fa[x]^1].cap+=a;
        x=e[fa[x]].u;
    }
    return a;
}

int isap()
{
    int i,x,ok,min,flow=0;
    mem(num,0);
    bfs();
    for(i=0;i<n;i++)num[d[i]]++;
    for(i=0;i<n;i++)cur[i]=first[i];
    x=s;
    while(d[s]<n){
        if(x==t){
            flow+=augment();
            x=s;
        }
        ok=0;
        for(i=cur[x];i!=-1;i=next[i]){
            if(e[i].cap && d[x]==d[e[i].v]+1){
                ok=1;
                fa[e[i].v]=i;
                cur[x]=i;
                x=e[i].v;
                break;
            }
        }
        if(!ok){
            min=n-1;
            for(i=first[x];i!=-1;i=next[i])
                if(e[i].cap && d[e[i].v]<min)min=d[e[i].v];
            if(--num[d[x]]==0)break;
            num[d[x]=min+1]++;
            cur[x]=first[x];
            x=e[fa[x]].u;
        }
    }
    return flow;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,a,b,val;
    while(~scanf("%d%d",&n,&m))
    {
        mm=0;
        mem(first,-1);
        s=0,t=n+1;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a,&b);
            adde1(s,i,a);
            adde1(i,t,b);
        }
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&val);
            adde2(a,b,val);
        }

        n+=2;
        printf("%d\n",isap());
    }
    return 0;
}