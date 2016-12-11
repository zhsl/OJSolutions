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
const int MAX=20010,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int num[MAX],coul[MAX],cour[MAX],sum[100010<<2];
int T,n,a,b,mau,s;

void update(int l,int r,int rt,int c)
{
    if(l==r){
        sum[rt]++;
        return;
    }
    int mid=(l+r)>>1;
    if(c<=mid)update(lson,c);
    else update(rson,c);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void query(int l,int r,int rt)
{
    if(l>=a && r<=b){
        s+=sum[rt];
        return;
    }
    int mid=(l+r)>>1;
    if(a<=mid)query(lson);
    if(b>mid)query(rson);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    LL ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        mau=-INF;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",num+i);
            if(num[i]>mau)mau=num[i];
        }

        mem(sum,0);
        for(i=0,a=1;i<n;i++){
            b=num[i];
            s=0;
            query(1,mau,1);
            coul[i]=s;
            update(1,mau,1,num[i]);
        }
        mem(sum,0);
        for(i=n-1,b=mau;i>=0;i--){
            a=num[i];
            s=0;
            query(1,mau,1);
            cour[i]=s;
            update(1,mau,1,num[i]);
        }
        for(i=1;i<n;i++)
            ans+=coul[i]*cour[i];

        printf("%I64d\n",ans);
    }
    return 0;
}