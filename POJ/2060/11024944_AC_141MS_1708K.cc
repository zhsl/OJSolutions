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
const int MAX=510,INF=200000000;

int vis[MAX],y[MAX],g[MAX][MAX];
int T,n;
struct Node{
    int t,x1,y1,x2,y2;
}nod[MAX];

int dfs(int u)
{
    int v;
    for(v=0;v<n;v++){
        if(g[u][v] && !vis[v]){
            vis[v]=1;
            if(y[v]==-1 || dfs(y[v])){
                y[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int i,j,ans;
    char s[8];
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        mem(g,0);
        mem(y,-1);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s%d%d%d%d",s,&nod[i].x1,&nod[i].y1,&nod[i].x2,&nod[i].y2);
            nod[i].t=((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
        }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j && nod[i].t+abs(nod[i].x1-nod[i].x2)+abs(nod[i].y1-nod[i].y2)
                   +abs(nod[i].x2-nod[j].x1)+abs(nod[i].y2-nod[j].y1)+1<=nod[j].t)
                    g[i][j]=1;
            }
        }

        for(i=0;i<n;i++){
            mem(vis,0);
            if(dfs(i))ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}