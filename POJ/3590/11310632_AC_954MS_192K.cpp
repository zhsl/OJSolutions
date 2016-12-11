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
#define pdi pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=110,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

int A[N],list[N][N],ans[N],one[N];
int n,k,T;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

void dfs(int cur,int val,int la)
{
    if(val<=la){
        int j,t=A[1],sum=n-A[1];
        if(A[1]==1)sum++;
        for(j=2;j<cur;j++){
            sum-=A[j];
            t=t/gcd(t,A[j])*A[j];
        }
        if( t>ans[n] || (t==ans[n] && sum>one[n]) ){
            ans[n]=t;
            for(j=1;j<cur;j++)list[n][j]=A[j];
            list[n][0]=cur-1;
            one[n]=sum;
        }
        return;
    }
    int i;
    for(i=la+1;i<=val && i<=23;i++){
        A[cur]=i;
        dfs(cur+1,val-i,i);
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(!list[n][0])dfs(1,n,0);
        printf("%d",ans[n]);
        if(one[n]){
            t=one[n]+1;
            for(i=1;i<=one[n];i++)printf(" %d",i);
        }
        else t=1;
        for(i=1;i<=list[n][0];i++){
            if(list[n][i]==1)continue;
            for(j=1;j<list[n][i];j++)
                printf(" %d",t+j);
            printf(" %d",t);
            t+=list[n][i];
        }
        putchar('\n');
    }
    return 0;
}