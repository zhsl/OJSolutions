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
const int MAX=4010,INF=0x3f3f3f3f,MOD=9999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

struct Node{
    int a,c,next;
}e[MAX*MAX*2];
int num[MAX][4],g[MAX*MAX],hal[MOD],har[MOD];
int n,m;

int build(int *ha,int a)
{
    int i,t=(a%MOD+MOD)%MOD;
    for(i=ha[t];i!=-1;i=e[i].next){
        if(a==e[i].a)
            return ++e[i].c;
    }
    e[m].a=a;e[m].c=1;
    e[m].next=ha[t];
    ha[t]=m++;
    return 0;
}

int find(int *ha,int a)
{
    int i,t=(a%MOD+MOD)%MOD;
    for(i=ha[t];i!=-1;i=e[i].next){
        if(a==e[i].a)
            return e[i].c;
    }
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int i,j,ans,t;
    scanf("%d",&n);
    ans=m=0;
    g[0]=0;
    mem(hal,-1);
    mem(har,-1);
    for(i=0;i<n;i++)
        scanf("%d%d%d%d",num[i],num[i]+1,num[i]+2,num[i]+3);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            t=-num[i][0]-num[j][1];
            if(!build(hal,t))
                g[++g[0]]=t;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            t=num[i][2]+num[j][3];
            build(har,t);
        }
    }
    for(i=1;i<=g[0];i++)
        if(t=find(har,g[i]))ans+=find(hal,g[i])*t;

    printf("%d\n",ans);
    return 0;
}