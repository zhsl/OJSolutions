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
const int N=11,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const double DNF=1e13;

LL a[N],m[N];
int n;

void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b){d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

LL china()
{
    int i;
    LL M=1,w,d,y,x=0;
    for(i=0;i<n;i++)M*=m[i];
    for(i=0;i<n;i++){
        w=M/m[i];
        exgcd(m[i],w,d,d,y);
        x=(x+y*a[i])%M;
    }
    return (x+M)%M;
}

LL phi(LL n)
{
    int i,j;
    LL m,ans=n;
    m=(LL)sqrt(n+0.5);
    for(i=2;i<m && i<n;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    LL n;
    while(~scanf("%I64d",&n) && n)
    {
        printf("%I64d\n",phi(n));
    }
    return 0;
}