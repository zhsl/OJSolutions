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
const int N=310,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

LL n,m;

LL C(LL n,LL m)
{
    m=Min(m,n-m);
    LL s=1,i;
    for(i=0;i<m;i++)s=s*(n-i)/(i+1);
    return s;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    while(~scanf("%I64d%I64d",&n,&m) && (n||m))
    {
        printf("%I64d\n",C(n+m,n));
    }
    return 0;
}