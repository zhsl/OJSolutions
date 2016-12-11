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
//#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=10010,INF=0x3f3f3f3f,MOD=1000000007;
const double DNF=100000000000;

int d[N];
LL f[N];
int l1,l2,l3,c1,c2,c3,n,s,e;

LL binary(int low,int i,int cost)
{
    int l=s,r=i,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(d[mid]>=low)r=mid;
        else l=mid+1;
    }
    return f[l]+cost;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,t;
    while(~scanf("%d%d%d%d%d%d",&l1,&l2,&l3,&c1,&c2,&c3))
    {
        mem(f,INF);
        scanf("%d%d%d",&n,&s,&e);
        for(i=2;i<=n;i++)
            scanf("%d",&d[i]);
        if(s>e)t=s,s=e,e=t;

        f[s]=0;
        for(i=s+1;i<=e;i++){
            t=d[i]-l1;
            f[i]=Min(f[i],binary(t,i,c1));
            t=d[i]-l2;
            f[i]=Min(f[i],binary(t,i,c2));
            t=d[i]-l3;
            f[i]=Min(f[i],binary(t,i,c3));
        }

        printf("%I64d\n",f[e]);
    }
    return 0;
}