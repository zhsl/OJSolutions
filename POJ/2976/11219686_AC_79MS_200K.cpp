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
const int N=1010,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

double d[N];
int a[N],b[N];
int n,k;

double binary()
{
    int i;
    double l=0,r=1,mid,s;
    while(r-l>1e-6){
        mid=l+(r-l)/2;
        for(i=0;i<n;i++)d[i]=a[i]-mid*b[i];
        sort(d,d+n);
        for(s=0,i=n-1;i>=k;i--)s+=d[i];
        if(s>0)l=mid;
        else r=mid;
    }
    mid*=100;
    return mid;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d%d",&n,&k) && (n||k))
    {
        for(i=0;i<n;i++)scanf("%d",a+i);
        for(i=0;i<n;i++)scanf("%d",b+i);

        printf("%.0lf\n",binary());
    }
    return 0;
}