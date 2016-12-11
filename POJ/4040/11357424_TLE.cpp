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
#define LL long long
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=1000010,INF=0x3f3f3f3f,MOD=1000000007;
const double DNF=100000000000;
 
int num[N],low[N<<4],s[N];
int n,c,sum,a;
 
void build(int l,int r,int rt)
{
    if(l==r){
        low[rt]=s[l];
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    low[rt]=Min(low[rt<<1],low[rt<<1|1]);
}
 
void update(int l,int r,int rt)
{
    if(l==r){
        low[rt]=sum+c;
     //   printf("  %d %d\n",l,low[rt]);
        return;
    }
    int mid=(l+r)>>1;
    if(a<=mid)update(lson);
    else update(rson);
    low[rt]=Min(low[rt<<1],low[rt<<1|1]);
}
 
int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,ans,t;
    while(~scanf("%d",&n) && n)
    {
        ans=sum=num[0]=c=0;
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        s[0]=num[0];
        for(i=1;i<n;i++)s[i]=s[i-1]+num[i];
        build(0,n-1,1);
     //   printf("%d %d %d\n",s[1],s[2],s[3]);
        if(sum>=0){
            for(i=0;i<n;i++){
                a=i;
                c+=num[i];
                update(0,n-1,1);
            //    printf(" %d %d\n",low[1],c);//
                if(low[1]-c>=0)ans++;
            }
        }
 
        printf("%d\n",ans);
    }
    return 0;
}