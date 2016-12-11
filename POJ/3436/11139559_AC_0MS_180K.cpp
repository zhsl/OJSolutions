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
#define put1(i,j,num) (li[i][0]|=(num<<(j<<1)))
#define get1(i,j) ((li[i][0]&(3<<(j<<1)))>>(j<<1))
#define put2(i,j,num) (li[i][1]|=(num<<j))
#define get2(i,j) ((li[i][1]&(1<<j))>>j)
const int N=102,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

struct Edge{
    int u,v,cap,flow;
}e[N*N];

int first[N],next[N*N],cur[N],d[N],w[51],li[51][2],num[N],p[N];
int n,m,S,T,mt;

void adde(int a,int b,int val)
{
    e[mt].u=a,e[mt].v=b;
    e[mt].cap=val,e[mt].flow=0;
    next[mt]=first[a],first[a]=mt++;
    e[mt].u=b,e[mt].v=a;
    e[mt].cap=0,e[mt].flow=0;
    next[mt]=first[b],first[b]=mt++;
}

int ok(int a,int b)
{
    int i;
    for(i=0;i<n;i++){
        if(get1(b,i)!=2 && get1(b,i)!=get2(a,i))
            return 0;
    }
    return 1;
}

void getg()
{
    int i,j,flag;
    for(i=1;i<=m;i++)
        adde(i,i+m,w[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            if(i!=j && ok(i,j))adde(i+m,j,INF);
        for(i=1;i<=m;i++){
            for(j=flag=0;j<n;j++)
                if(get1(i,j)==1){flag=1;break;}
            if(!flag)adde(S,i,INF);
            if(li[i][1]==((1<<n)-1))adde(i+m,T,INF);
    }
}

int augment()
{
    int i=T,a=INF;
    while(i!=S){
        a=Min(a,e[p[i]].cap-e[p[i]].flow);
        i=e[p[i]].u;
    }
    i=T;
    while(i!=S){
        e[p[i]].flow+=a;
        e[p[i]^1].flow-=a;
        i=e[p[i]].u;
    }
    return a;
}

int isap()
{
    int x,i,min,flow=0,ok;
    mem(d,0);mem(num,0);
    num[0]=T+1;
    for(i=0;i<=T;i++)cur[i]=first[i];
    x=S;
    while(d[S]<=T)
    {
        if(x==T){
            flow+=augment();
            x=S;
        }
        ok=0;
        for(i=cur[x];i!=-1;i=next[i]){
            if(e[i].cap>e[i].flow && d[x]==d[e[i].v]+1){
                ok=1;
                p[e[i].v]=i;
                cur[x]=i;
                x=e[i].v;
                break;
            }
        }
        if(!ok){
            min=T;
            for(i=first[x];i!=-1;i=next[i])
                if(e[i].cap>e[i].flow && d[e[i].v]<min)min=d[e[i].v];
            if(--num[d[x]]==0)break;
            num[d[x]=min+1]++;
            cur[x]=first[x];
            if(x!=S)x=e[p[x]].u;
        }
    }
    return flow;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,t;
    int ans[N][3],cou;
    while(~scanf("%d%d",&n,&m))
    {
        cou=mt=S=0;
        T=2*m+1;
        mem(li,0);
        mem(first,-1);
        for(i=1;i<=m;i++){
            scanf("%d",&w[i]);
            for(j=0;j<n;j++){
                scanf("%d",&t);
                put1(i,j,t);
            }
            for(j=0;j<n;j++){
                scanf("%d",&t);
                put2(i,j,t);
            }
        }

        getg();
        printf("%d",isap());

        for(i=m;i<T;i++){
            for(j=first[i];j!=-1;j=next[j]){
                if(e[j].v<=m && e[j].flow>0){
                    ans[cou][0]=i-m;
                    ans[cou][1]=e[j].v;
                    ans[cou++][2]=e[j].flow;
                }
            }
        }
        printf(" %d\n",cou);
        for(i=0;i<cou;i++)
            printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
    return 0;
}