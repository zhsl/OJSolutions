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
const int N=500010,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int num[N],temp[N];
int n;
LL ans;

void sort(int l,int r)
{
    if(l==r)return;
    int i,j,k,mid=(l+r)>>1;
    sort(l,mid);
    sort(mid+1,r);
    for(i=k=l,j=mid+1;i<=mid && j<=r;){
        if(num[i]<num[j]){
            ans+=j-mid-1;
            temp[k++]=num[i++];
        }
        else temp[k++]=num[j++];
    }
    while(i<=mid){
        ans+=j-mid-1;
        temp[k++]=num[i++];
    }
    while(j<=r)
        temp[k++]=num[j++];
    for(i=l;i<=r;i++)
        num[i]=temp[i];
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d",&n) && n)
    {
        ans=0;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);

        sort(0,n-1);
        printf("%I64d\n",ans);
    }
    return 0;
}