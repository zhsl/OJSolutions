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
const int N=32010,INF=0x3f3f3f3f,MOD=4001,STA=1000010;
const double DNF=100000000000;

int sum[N<<2],ans[N/2];
int n,a,b,ret;

void update(int l,int r,int rt)
{
    if(l==r){
        sum[rt]++;
        return;
    }
    int mid=(l+r)>>1;
    if(a<=mid)update(lson);
    else update(rson);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void query(int l,int r,int rt)
{
    if(r<=a){
        ret+=sum[rt];
        return;
    }
    int mid=(l+r)>>1;
    query(lson);
    if(a>mid)query(rson);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d",&n))
    {
        mem(ans,0);
        mem(sum,0);
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            ret=0;
            query(0,N-1,1);
            ans[ret]++;
            update(0,N-1,1);
        }

        for(i=0;i<n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}