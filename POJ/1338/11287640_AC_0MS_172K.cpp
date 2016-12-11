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
const int N=1510,INF=0x3f3f3f3f,MOD=1999997;
const double DNF=100000000000;

int ans[N],w[3];
int n;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,t[3];
    ans[1]=w[0]=w[1]=w[2]=1;
    for(i=2;i<=1500;i++){
        while((t[0]=2*ans[w[0]])<=ans[i-1])w[0]++;
        while((t[1]=3*ans[w[1]])<=ans[i-1])w[1]++;
        while((t[2]=5*ans[w[2]])<=ans[i-1])w[2]++;
        if(t[0]<=t[1] && t[0]<=t[2])ans[i]=t[0];
        else if(t[1]<=t[0] && t[1]<=t[2])ans[i]=t[1];
        else if(t[2]<=t[0] && t[2]<=t[1])ans[i]=t[2];
    }
    while(~scanf("%d",&n) && n)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}