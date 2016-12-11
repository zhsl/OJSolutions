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
const int N=510000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int main()
{
 //   freopen("in.txt","r",stdin);
    int a,b,t,tt,ans;
    while(~scanf("%d%d",&a,&b))
    {
        ans=t=0;
        while(a || t>=b){
            ans+=tt=a;
            a=(a+t)/b;
            t=tt%b;
        }
        printf("%d\n",ans);
    }
    return 0;
}