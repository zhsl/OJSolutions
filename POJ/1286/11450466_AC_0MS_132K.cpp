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
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=25,INF=0x3f3f3f3f,MOD=40001,STA=8000010;
const double DNF=1e13;

LL tri[N];
int n;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    LL ans;
    tri[0]=1;
    for(i=1;i<24;i++)tri[i]=tri[i-1]*3;
    while(~scanf("%d",&n) && n!=-1)
    {
        ans=0;
        for(i=0;i<n;i++)ans+=tri[gcd(n,i)];
        if(n&1)ans+=(LL)n*tri[n/2+1];
        else ans+=(LL)n/2*(tri[n/2]+tri[n/2+1]);
        printf("%I64d\n",n?ans/n/2:0);
    }
    return 0;
}