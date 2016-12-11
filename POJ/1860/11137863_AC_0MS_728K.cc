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
const int N=110,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

struct Edge{
    int u,v;
    double r,s;
}e[N*N];

double d[N];
double v;
int first[N],next[N*N],inq[N],cou[N];
int n,m,s,mt;

void adde(int a,int b,double r,double s)
{
    e[mt].u=a,e[mt].v=b;
    e[mt].r=r,e[mt].s=s;
    next[mt]=first[a],first[a]=mt++;
}

int spfa()
{
    int x,i;
    double t;
    queue<int> q;
    mem(inq,0);mem(cou,0);
    for(i=1;i<=n;i++)d[i]=-1;
    d[s]=v;
    cou[s]=1;
    q.push(s);
    while(!q.empty())
    {
        x=q.front();q.pop();
        inq[x]=0;
        for(i=first[x];i!=-1;i=next[i]){
            t=(d[x]-e[i].s)*e[i].r;
            if(t>=0 && t>d[e[i].v]){
                d[e[i].v]=t;
                if(!inq[e[i].v]){
                    if(++cou[e[i].v]>=n)return 1;
                    inq[e[i].v]=1;
                    q.push(e[i].v);
                }
            }
        }
    }
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b;
    double r1,s1,r2,s2;
    while(~scanf("%d%d%d%lf",&n,&m,&s,&v))
    {
        mt=0;
        mem(first,-1);
        for(i=0;i<m;i++){
            scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&s1,&r2,&s2);
            adde(a,b,r1,s1);
            adde(b,a,r2,s2);
        }

        printf("%s\n",spfa()?"YES":"NO");
    }
    return 0;
}