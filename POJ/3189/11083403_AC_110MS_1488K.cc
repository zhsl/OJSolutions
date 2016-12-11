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
#define LL __int64
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=2100,INF=0x3f3f3f3f;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

struct Edge{
    int u,v,cap;
}e[MAX*MAX*2];

int first[MAX],next[MAX*MAX*2];
int w[MAX][25],d[MAX],cur[MAX],p[MAX],num[MAX],hav[25];
int n,m,s,t,mt;

void adde(int a,int b,int val)
{
    e[mt].u=a;e[mt].v=b;
    e[mt].cap=val;
    next[mt]=first[a];first[a]=mt++;
    e[mt].u=b;e[mt].v=a;
    e[mt].cap=0;
    next[mt]=first[b];first[b]=mt++;
}

int augment()
{
    int x=t,a=INF;
    while(x!=s){
        a=Min(a,e[p[x]].cap);
        x=e[p[x]].u;
    }
    x=t;
    while(x!=s){
        e[p[x]].cap-=a;
        e[p[x]^1].cap+=a;
        x=e[p[x]].u;
    }
    return a;
}

int isap()
{
    int i,flow=0,x,ok,min;
    mem(d,0);mem(num,0);
    num[0]=t+1;
    for(i=0;i<=t;i++)cur[i]=first[i];
    x=s;
    while(d[s]<=t){
        if(x==t){
            flow+=augment();
            x=s;
        }
        ok=0;
        for(i=cur[x];i!=-1;i=next[i]){
            if(e[i].cap && d[x]==d[e[i].v]+1){
                ok=1;
                p[e[i].v]=i;
                cur[x]=i;
                x=e[i].v;
                break;
            }
        }
        if(!ok){
            min=t;
            for(i=first[x];i!=-1;i=next[i])
                if(e[i].cap && d[e[i].v]<min)min=d[e[i].v];
            if(--num[d[x]]==0)break;
            num[d[x]=min+1]++;
            cur[x]=first[x];
            if(x!=s)x=e[p[x]].u;
        }
    }
    return flow;
}

int binary(int r)
{
    int i,j,low=r,high=m+1,mid,ok=0;
    while(low<high){
        mid=(low+high)>>1;
        mt=0;
        mem(first,-1);
        for(i=1;i<=n;i++){
            adde(s,i,1);
            for(j=r;j<=mid;j++)
                adde(i,n+w[i][j],1);
        }
        for(i=1;i<=m;i++)
            adde(n+i,t,hav[i]);
        int tt=isap();
        if(tt<n)low=mid+1;
        else {
            if(tt==n)ok=1;
            high=mid;
        }
    }
    return ok?low-r+1:INF;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,ans,tt;
    while(~scanf("%d%d",&n,&m))
    {
        ans=INF;
        s=0,t=n+m+1;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&w[i][j]);
        for(i=1;i<=m;i++)
            scanf("%d",&hav[i]);

        for(i=1;i<=m;i++){
            tt=binary(i);
            if(tt<ans)ans=tt;
            if(ans==1)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}