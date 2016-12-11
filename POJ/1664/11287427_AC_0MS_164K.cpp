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
#define pdi pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=30,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000000;

int T,n,m;

int dfs(int val,int cur,int la)
{
    if(cur==0)return 1;
    if(val<=cur)return 0;
    int i,res=0;
    for(i=la;i<=val/2;i++)
        res+=dfs(val-i,cur-1,i);
    return res;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d%d",&m,&n);
        for(i=0;i<n && i<m;i++)
            ans+=dfs(m,i,1);
        printf("%d\n",ans);
    }
    return 0;
}