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
const int MAX=1010,INF=0x3f3f3f3f;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

struct Edge{
    int u,v,cap,w;
}e[MAX*20];

int d[MAX],first[MAX],next[MAX*20],inq[MAX],p[MAX];
int n,m,s,t,mt;

void adde(int a,int b,int c,int val){
    e[mt].u=a,e[mt].v=b,e[mt].cap=c,e[mt].w=val;
    next[mt]=first[a],first[a]=mt++;
    e[mt].u=b,e[mt].v=a,e[mt].cap=0,e[mt].w=val;
    next[mt]=first[b],first[b]=mt++;
}

int EK()
{
    int i,j,x,a,cast=0;
    queue<int> q;
    p[s]=-1;
    while(1){
        a=INF;
        mem(d,0x3f);
        mem(inq,0);
        d[s]=0;
        q.push(s);
        while(!q.empty()){
            x=q.front();q.pop();
            inq[x]=0;
            for(i=first[x];i!=-1;i=next[i]){
                if(e[i].cap && d[e[i].u]+e[i].w<d[e[i].v]){
                    d[e[i].v]=d[e[i].u]+e[i].w;
                    p[e[i].v]=i;
                    if(!inq[e[i].v]){
                        q.push(e[i].v);
                        inq[e[i].v]=1;
                    }
                }
            }
        }
        if(d[t]==INF)break;
        for(i=p[t];i!=-1;i=p[e[i].u])
            if(e[i].cap<a)a=e[i].cap;
        for(i=p[t];i!=-1;i=p[e[i].u]){
            e[i].cap-=a;
            e[i^1].cap+=a;
        }
        cast+=d[t]*a;
    }
    return cast;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,a,b,c;
    while(~scanf("%d%d",&n,&m))
    {
        t=n;
        s=mt=0;
        mem(first,-1);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            adde(a,b,1,c);
        }
        adde(s,1,2,0);

        printf("%d\n",EK());
    }
    return 0;
}