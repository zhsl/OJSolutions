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
const int MAX=110,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

char map[MAX][MAX];
int ma[128],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int n,m,s,ans1,ans2;

int dfs(int x,int y,int d)
{
    int t=map[x][y];
    if(x<0||x>=n || y<0||y>=m){
        ans1=d;
        return 1;
    }
    if(t<'A'){
        ans1=t;ans2=d-t;
        return 0;
    }
    map[x][y]=d;
    dfs(x+dx[ma[t]],y+dy[ma[t]],d+1);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    ma['N']=0,ma['E']=1,ma['S']=2,ma['W']=3;
    while(~scanf("%d%d%d",&n,&m,&s) && n)
    {
        for(i=0;i<n;i++)
            scanf("%s",map[i]);

        if(dfs(0,s-1,0))printf("%d step(s) to exit\n",ans1);
        else printf("%d step(s) before a loop of %d step(s)\n",ans1,ans2);
    }
    return 0;
}