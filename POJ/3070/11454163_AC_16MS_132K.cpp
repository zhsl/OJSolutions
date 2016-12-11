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
const int N=25,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const double DNF=1e13;

struct Matrix{
    LL ma[2][2];
    Matrix friend operator * (const Matrix& a,const Matrix& b){
        Matrix ret;
        mem(ret.ma,0);
        int i,j,k;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                for(k=0;k<2;k++)
                    ret.ma[i][j]=(ret.ma[i][j]+a.ma[i][k]*b.ma[k][j])%MOD;
            }
        }
        return ret;
    }
}a,f;

int n;

void mutilpow(int k)
{
    int i,j;
    mem(f.ma,0);
    f.ma[0][0]=f.ma[1][1]=1;
    for(;k;k>>=1){
        if(k&1)f=f*a;
        a=a*a;
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    LL ans;
    while(~scanf("%d",&n) && n!=-1)
    {
        a.ma[0][0]=0;a.ma[0][1]=1;
        a.ma[1][0]=a.ma[1][1]=1;
        if(n>=2){
            mutilpow(n-2);
            ans=f.ma[1][0]+f.ma[1][1];
        }
        else ans=n;

        printf("%I64d\n",ans%MOD);
    }
    return 0;
}