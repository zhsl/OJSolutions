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

int f[N][N],list[N][N],one[N];
int n,k,T;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

void getans(int a)
{
    int i,k=0,cou,sum=n;
    for(i=2;i<=a;i++){
        if(a%i==0){
            list[n][++k]=1;
            while(a%i==0){
                list[n][k]*=i;
                a/=i;
            }
            sum-=list[n][k];
        }
    }
    if(a>1)sum-=list[n][++k]=a;
    sort(list[n],list[n]+k+1);
    list[n][0]=k;
    one[n]=sum;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,t;
    f[1][0]=f[1][1]=1;
    for(i=2;i<=100;i++){
        f[i][0]=f[i][1]=i;
        for(j=2;j<=i;j++){
            for(k=i-1;k>=j-1;k--)
                f[i][j]=Max(f[i][j],f[k][j-1]/gcd(f[k][j-1],i-k)*(i-k));
            f[i][0]=Max(f[i][0],f[i][j]);
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(!list[n][0])getans(f[n][0]);
        printf("%d",f[n][0]);
        for(i=1;i<=one[n];i++)
            printf(" %d",i);
        t=one[n]+1;
        for(i=1;i<=list[n][0];i++){
            for(j=1;j<list[n][i];j++)
                printf(" %d",j+t);
            printf(" %d",t);
            t+=list[n][i];
        }
        putchar('\n');
    }
    return 0;
}