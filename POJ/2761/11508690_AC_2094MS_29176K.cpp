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
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
const int N=100010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
//const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;
//
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
void swap(int& a,int& b){int t=a;a=b;b=t;}
void swap(LL& a,LL& b){LL t=a;a=b;b=t;}
//

int val[N],num[20][N],cnt[20][N];
LL sum[20][N],s[N];
int T,n,m,knum;
LL ksum;

void build(int u,int l,int r)
{
    if(l==r){
        sum[u][l]=num[u][l];
        return;
    }
    int i,mid,midnum,kl,kr,lsame;
    LL s=0;
    mid=(l+r)>>1;
    kl=l;kr=mid+1;lsame=mid-l+1;
    midnum=val[mid];
    for(i=l;i<=mid;i++)
        if(val[i]<midnum)lsame--;
    for(i=l;i<=r;i++){
        if(num[u][i]<midnum || (num[u][i]==midnum && lsame)){
            if(num[u][i]==midnum)lsame--;
            num[u+1][kl++]=num[u][i];
            sum[u][i]=s+(LL)num[u][i];
            s=sum[u][i];
        }
        else {
            num[u+1][kr++]=num[u][i];
            sum[u][i]=s;
        }
        cnt[u][i]=kl-l;
    }
    build(u+1,l,mid);
    build(u+1,mid+1,r);
}

void query(int u,int l,int r,int a,int b,int k)
{
    if(a==b){
        knum=num[u][a];
        ksum+=num[u][a];
        return;
    }
    int i,t,mid,cnta;
    mid=(l+r)>>1;
    cnta=(a>l?cnt[u][a-1]:0);
    t=cnt[u][b]-cnta;
    if(k<=t){
        query(u+1,l,mid,l+cnta,l+cnt[u][b]-1,k);
    }
    else{
        ksum+=sum[u][b]-(a>l?sum[u][a-1]:0);
        query(u+1,mid+1,r,
              mid+a-l-cnta+1,mid+b-l-cnt[u][b]+1,k-t);
    }
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,a,b,k;
    while(~scanf("%d%d",&n,&m))
    {
        s[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&val[i]);
            num[0][i]=val[i];
            s[i]=s[i-1]+val[i];
        }
        sort(val+1,val+n+1);
        build(0,1,n);

        while(m--){
            scanf("%d%d%d",&a,&b,&k);
            query(0,1,n,a,b,k);
            printf("%d\n",knum);
        }
        putchar('\n');
    }
    return 0;
}