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
}e[5*N];
double d[N];
int w[N],inq[N],first[N],next[5*N],cou[N];
int n,m,mt;

void adde(int a,int b,int c)
{
    e[mt].u=a,e[mt].v=b,e[mt].w=c;
    next[mt]=first[a],first[a]=mt++;
}

int SPFA(int s,double mid)
{
    int i,j,u,v;
    queue<int> q;
    for(i=1;i<=n;i++)d[i]=-DNF;d[s]=0;
    mem(inq,0);mem(cou,0);
    q.push(s);
    while(!q.empty()){
        u=q.front();q.pop();
        inq[u]=0;
        for(i=first[u];i!=-1;i=next[i]){
            v=e[i].v;
            if(d[u]+w[u]-e[i].w*mid>d[v]){
                d[v]=d[u]+w[u]-e[i].w*mid;
                if(!inq[v]){
                    inq[v]=1;
                    if(++cou[v]==n)return 1;
                    q.push(v);
                }
            }
        }
    }
    return 0;
}

double binary()
{
    double l=0,r=1000,mid;
    while(r-l>1e-3){
        mid=l+(r-l)/2;
        if(SPFA(1,mid)>0)l=mid;
        else r=mid;
    }
    return mid;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,a,b,c;
    while(~scanf("%d%d",&n,&m))
    {
        mt=0;
        mem(first,-1);
        for(i=1;i<=n;i++)
            scanf("%d",&w[i]);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            adde(a,b,c);
        }

        printf("%.2lf\n",binary());
    }
    return 0;
}