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
const int MAX=20,INF=200000000;

int w[MAX][MAX],S[MAX],T[MAX],lx[MAX],ly[MAX],A[MAX],y[MAX],vis[MAX];
int Tu,n,ans,anscou,slack;

int match(int u)
{
    int v,t;
    S[u]=1;
    for(v=1;v<=n;v++){
        t=w[u][v]-lx[u]-ly[v];
        if(!t){
            if(!T[v]){
                T[v]=1;
                if(!y[v] || match(y[v])){
                    y[v]=u;
                    return 1;
                }
            }
        }
        else if(t<slack)slack=t;
    }
    return 0;
}

void KM()
{
    int i,j,a;
    mem(ly,0);
    for(i=1;i<=n;i++){
        lx[i]=w[i][1];
        for(j=2;j<=n;j++)
            if(w[i][j]<lx[i])lx[i]=w[i][j];
    }
    for(i=1;i<=n;i++){
        while(1){
            slack=INF;
            mem(S,0);mem(T,0);
            if(match(i))break;
            for(j=1;j<=n;j++){
                if(S[j])lx[j]+=slack;
                if(T[j])ly[j]-=slack;
            }
        }
    }
}

void dfs(int cur,int s)
{
    if(s>ans || (cur==n+1 && s!=ans))return ;
    int i;
    if(cur==n+1){
        printf("Best Pairing %d\n",anscou++);
        for(i=1;i<=n;i++)
            printf("Supervisor %d with Employee %d\n",i,A[i]);
        return ;
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            A[cur]=i;
            dfs(cur+1,s+w[cur][i]);
            vis[i]=0;
        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,t,k=1;
    scanf("%d",&Tu);
    while(Tu--)
    {
        mem(y,0);
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&t);
                w[t][i]=j;
            }
        }
        for(i=1;i<=n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&t);
                w[i][t]+=j;
            }
        }

        KM();

        for(ans=0,i=1;i<=n;i++)
            ans+=w[y[i]][i];
        printf("Data Set %d, Best average difference: %.6f\n",k++,ans*0.5/n);
        anscou=1;
        mem(vis,0);
        dfs(1,0);
        if(Tu)putchar('\n');
    }
    return 0;
}