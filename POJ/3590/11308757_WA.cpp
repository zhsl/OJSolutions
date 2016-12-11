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

int A[N],list[N][N],ans[N];
int n,k;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

void dfs(int cur,int val,int la)
{
    if(val<=la){
        int j,t=A[1];
        for(j=2;j<cur;j++){
            t=t/gcd(t,A[j])*A[j];
        }
        if(t>ans[n]){
            ans[n]=t;
            for(j=1;j<cur;j++)list[n][j]=A[j];
            list[n][0]=cur-1;
        }
        return;
    }
    int i;
    for(i=la+1;i<=val && i<=19;i++){
        A[cur]=i;
        dfs(cur+1,val-i,i);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int i,j,t;
    while(~scanf("%d",&n))
    {
        if(!list[n][0])dfs(1,n,0);
        printf("%d",ans[n]);
        int sum=0;
        for(i=1;i<=list[n][0];i++)sum+=list[n][i];
        if(sum!=n){
            sum=n-sum;
            t=sum+1;
            for(i=1;i<=sum;i++)printf(" %d",i);
        }
        else t=1;
        for(i=1;i<=list[n][0];i++){
            for(j=1;j<list[n][i];j++)
                printf(" %d",t+j);
            printf(" %d",t);
            t+=list[n][i];
        }
        putchar('\n');
    }
    return 0;
}