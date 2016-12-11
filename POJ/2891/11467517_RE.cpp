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
const int N=10000010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const double DNF=1e13;

LL a[N],m[N];
int n;

void exgcd(LL a,LL b,LL& d,LL& x,LL& y)
{
    if(!b){d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

LL Modline(int n)
{
    int i;
    LL ans,d,x,y,A,M;
    ans=a[0];A=a[0];M=m[0];
    for(i=1;i<n;i++){
        exgcd(m[i],M,d,x,y);
        if((A-a[i])%d!=0)return -1;
        ans=(m[i]*x*A+M*y*a[i])/d;
        A=ans;M*=m[i];
    }
    return (ans+M)%M;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++){
            scanf("%I64d%I64d",&m[i],&a[i]);
        }

        printf("%I64d\n",Modline(n));
    }
    return 0;
}