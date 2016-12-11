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
const int MAX=120,INF=200000000;
struct Node{
    int x,y;
}nod[MAX];
struct Square{
    int x1,y1,x2,y2;
}squ[MAX];

int g[MAX][MAX],vis[MAX],y[MAX],ans[MAX];
int n,have;

void getG()
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(nod[j].x>squ[i].x1&&nod[j].x<squ[i].x2
               && nod[j].y>squ[i].y1&&nod[j].y<squ[i].y2)
               g[i][j]=1;
        }
    }
}

int match(int u)
{
    int v;
    for(v=0;v<n;v++){
        if(g[u][v] && !vis[v]){
            vis[v]=1;
            if(y[v]==-1 || match(y[v])){
                if(have)y[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k=1,flag,t;
    while(~scanf("%d",&n) && n)
    {
        flag=1;
        mem(y,-1);
        mem(ans,-1);
        mem(g,0);

        for(i=0;i<n;i++)
            scanf("%d%d%d%d",&squ[i].x1,&squ[i].x2,&squ[i].y1,&squ[i].y2);
        for(i=0;i<n;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);

        getG();
        have=1;
        for(i=0;i<n;i++){
            mem(vis,0);
            match(i);
        }

        have=0;
        for(i=0;i<n;i++){
            if(y[i]!=-1){
                mem(vis,0);
                t=y[i];
                g[t][i]=0;
                y[i]=-1;
                if(!match(t))
                    ans[t]=i;
                g[t][i]=1;
                y[i]=t;
            }
        }

        printf("Heap %d\n",k++);
        for(i=0;i<n;i++){
            if(ans[i]!=-1){
                if(flag){
                    flag=0;
                    printf("(%c,%d)",i+'A',ans[i]+1);
                }
                else printf(" (%c,%d)",i+'A',ans[i]+1);
            }
        }
        if(flag)printf("none");
        printf("\n\n");
    }
    return 0;
}