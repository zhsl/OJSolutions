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
const int MAX=110,INF=200000000;

struct Node{
    int x,y;
}H[MAX],M[MAX];

char map[MAX][MAX];
int w[MAX][MAX],lx[MAX],ly[MAX],S[MAX],T[MAX],y[MAX];
int n,m,k1,k2;

int dfs(int u)
{
    S[u]=1;
    int v;
    for(v=0;v<k1;v++){
        if(w[u][v]==lx[u]+ly[v] && !T[v]){
            T[v]=1;
            if(y[v]==-1 || dfs(y[v])){
                y[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

void update()
{
    int i,j,min;
    min=INF;
    for(i=0;i<k1;i++)if(S[i])
        for(j=0;j<k1;j++)if(!T[j])
            min=Min(min,w[i][j]-lx[i]-ly[j]);
    for(i=0;i<k1;i++){
        if(S[i])lx[i]+=min;
        if(T[i])ly[i]-=min;
    }
}

void KM()
{
    mem(y,-1);
    mem(ly,0);
    int i,j;
    for(i=0;i<k1;i++){
        lx[i]=INF;
        for(j=0;j<k1;j++)
            if(w[i][j]<lx[i])lx[i]=w[i][j];
    }
    for(i=0;i<k1;i++){
        while(1){
            mem(S,0);mem(T,0);
            if(dfs(i))break;
            update();
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int i,j,ans;
    while(~scanf("%d%d",&n,&m) && n&&m)
    {
        ans=k1=k2=0;
        mem(w,0);
        for(i=0;i<n;i++){
            scanf("%s",map[i]);
            for(j=0;j<m;j++){
                if(map[i][j]=='m')
                    M[k1].x=i,M[k1++].y=j;
                if(map[i][j]=='H')
                    H[k2].x=i,H[k2++].y=j;
            }
        }
        for(i=0;i<k1;i++)
            for(j=0;j<k1;j++)
                w[i][j]=abs(M[i].x-H[j].x)+abs(M[i].y-H[j].y);

        KM();
        for(i=0;i<k1;i++)
            ans+=w[y[i]][i];

        printf("%d\n",ans);
    }
}