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
#define LL long long
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=55,INF=0x3f3f3f3f;

int w[MAX][MAX*MAX],S[MAX],T[MAX*MAX],lx[MAX],ly[MAX*MAX],y[MAX*MAX];
int Test,n,m,slack;

int dfs(int u)
{
    int v,t;
    S[u]=1;
    for(v=0;v<m;v++){
        t=w[u][v]-lx[u]-ly[v];
        if(!t){
            if(!T[v]){
                T[v]=1;
                if(y[v]==-1 || dfs(y[v])){
                    y[v]=u;
                    return 1;
                }
            }
        }
        else if(t<slack)slack=t;
    }
    return 0;
}

double KM()
{
    int i,j;
    double s;
    mem(ly,0);
    mem(y,-1);
    for(i=0;i<n;i++){
        lx[i]=INF;
        for(j=0;j<m;j++)
            if(w[i][j]<lx[i])lx[i]=w[i][j];
    }
    for(i=0;i<n;i++){
        while(1){
            slack=INF;
            mem(S,0);mem(T,0);
            if(dfs(i))break;
            for(j=0;j<n;j++)if(S[j])lx[j]+=slack;
            for(j=0;j<m;j++)if(T[j])ly[j]-=slack;
        }
    }
    for(i=s=0;i<m;i++)
        if(y[i]!=-1)s+=w[y[i]][i];
    return s;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,t;
    double ans;
    scanf("%d",&Test);
    while(Test--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&w[i][j]);
        for(i=0,t=m;i<t;i++)
            for(j=2;j<=50;j++,m++)
                for(k=0;k<n;k++)
                    w[k][m]=w[k][i]*j;
        ans=KM();

        printf("%.6f\n",ans/n);
    }
    return 0;
}