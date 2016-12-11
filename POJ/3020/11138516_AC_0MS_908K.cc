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
const int N=50,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

char map[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int sx[N][N],sy[N][N],p[N*N],vis[N*N],y[N*N],g[210][210];
int T,n,m,nx,ny;

void getg()
{
    int i,j,t,q,x,y;
    t=1;
    for(i=nx=0;i<n;i++)
        for(j=t=!t;j<m;j+=2)
            if(map[i][j]=='*')sx[i][j]=nx++;
    t=0;
    for(i=ny=0;i<n;i++)
        for(j=t=!t;j<m;j+=2)
            if(map[i][j]=='*')sy[i][j]=ny++;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(sx[i][j]!=-1){
                for(q=0;q<4;q++){
                    x=i+dx[q];
                    y=j+dy[q];
                    if(x>=0&&x<n && y>=0&&y<m && sy[x][y]!=-1)
                        g[sx[i][j]][sy[x][y]]=1;
                }
            }
        }
    }
}

int dfs(int x)
{
    int v;
    for(v=0;v<ny;v++){
        if(g[x][v] && !vis[v]){
            vis[v]=1;
            if(p[v]==-1 || dfs(p[v])){
                p[v]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        mem(sx,-1);mem(sy,-1);
        mem(p,-1);
        mem(g,0);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",map[i]);

        getg();
        for(i=0;i<nx;i++){
            mem(vis,0);
            if(dfs(i))ans++;
        }

        printf("%d\n",nx+ny-ans);
    }
    return 0;
}