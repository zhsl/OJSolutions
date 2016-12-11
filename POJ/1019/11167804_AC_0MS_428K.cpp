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
const int N=33010,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

LL sum[N];
int T,n;

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,t;
    sum[1]=j=1;
    for(i=2;i<10;i++){j+=1;sum[i]=sum[i-1]+j;}
    for(;i<100;i++){j+=2;sum[i]=sum[i-1]+j;}
    for(;i<1000;i++){j+=3;sum[i]=sum[i-1]+j;}
    for(;i<10000;i++){j+=4;sum[i]=sum[i-1]+j;}
    for(;i<32000;i++){j+=5;sum[i]=sum[i-1]+j;}
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;sum[i]<n;i++);
        n-=sum[i-1];

        for(i=1,j=9;n>0;n-=j*i,i++,j*=10);
        n+=(j/=10)*(--i);
        for(j=1,t=i;--t;j*=10);

        for(;n>0;j++)n-=i;
        j--,n=-n;
        for(;n;j/=10,n--);
        printf("%d\n",j%10);
    }
    return 0;
}