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
const int N=1000010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const double DNF=1e13;

int n;

void exgcd(LL a,LL b,LL& d,LL& x,LL& y)
{
    if(!b){d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

LL Modline(int n)
{
    LL d,x,y,A,M,a,m,Mod;
    scanf("%I64d%I64d",&M,&A);
    while(--n){
        scanf("%I64d%I64d",&m,&a);
        exgcd(M,m,d,x,y);
        if((A-a)%d!=0){
            while(--n)scanf("%I64d%I64d",&m,&a);
            return -1;
        }
        Mod=m/d;
        x=(x*((a-A)/d)%Mod+Mod)%Mod;
        A+=M*x;
        M=M/d*m;
    }
    return A;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d",&n))
    {
        printf("%I64d\n",Modline(n));
    }
    return 0;
}