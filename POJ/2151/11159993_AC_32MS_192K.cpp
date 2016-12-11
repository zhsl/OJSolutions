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
const int N=1010,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

double num[35],win[2],f[35][35];
int m,t,n;

void dp()
{
    int i,j;
    win[0]=win[1]=0;
    f[0][0]=1;
    for(j=1;j<=m;j++)
        f[0][j]=f[0][j-1]*(1-num[j]);
    for(j=1;j<=m;j++){
        for(i=1;i<=j;i++)
            f[i][j]=f[i][j-1]*(1-num[j])+f[i-1][j-1]*num[j];
    }
    for(i=1;i<n;i++)
        win[0]+=f[i][m];
    win[1]=1-f[0][m];
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    double ans1,ans2;
    while(~scanf("%d%d%d",&m,&t,&n) && (n||t||m))
    {
        ans1=ans2=1;
        for(i=1;i<=t;i++){
            for(j=1;j<=m;j++)
                scanf("%lf",&num[j]);
            dp();
            ans1*=win[1];
            ans2*=win[0];
        }

        printf("%.3lf\n",ans1-ans2);
    }
    return 0;
}