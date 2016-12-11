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
const int N=25,INF=0x3f3f3f3f,MOD=40001,STA=8000010;
const double DNF=1e13;

LL B[N][2],C[N][N],f[N][2];
int n,m;


LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}

void getC(int n)
{
    int i,j;
    n++;
    for(i=0;i<=n;i++)C[i][0]=C[i][i]=1;
    for(i=2;i<=n;i++){
        for(j=1;j<n;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}

void bernoulli(int n)
{
    int i,m;
    LL s[2],b[2],l,g;
    B[0][0]=1;B[0][1]=1;
    for(m=1;m<=n;m++){
        s[0]=1,s[1]=1;
        for(i=1;i<m;i++){
            b[0]=C[m+1][i]*B[i][0];
            b[1]=B[i][1];
            l=lcm(s[1],b[1]);
            s[0]=l/s[1]*s[0]+l/b[1]*b[0];
            s[1]=l;
        }
        s[0]=-s[0];
        if(s[0]){
            g=gcd(s[0],s[1]*C[m+1][m]);
            B[m][0]=s[0]/g;
            B[m][1]=s[1]*C[m+1][m]/g;
        }
        else B[m][0]=0,B[m][1]=1;
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    LL g,maxlcm;
    getC(20);
    bernoulli(20);
    while(~scanf("%d",&m))
    {
        for(i=0;i<=m;i++){
            g=gcd(C[m+1][i],B[i][1]);
            f[i][0]=C[m+1][i]/g*B[i][0];
            f[i][1]=B[i][1]/g;
        }
        maxlcm=f[0][1];
        for(i=1;i<=m;i++){
            maxlcm=lcm(maxlcm,f[i][1]);
        }
        if(maxlcm<0)maxlcm=-maxlcm;
        for(i=0;i<=m;i++){
            f[i][0]*=maxlcm/f[i][1];
        }
        f[1][0]+=maxlcm*(m+1);

        printf("%I64d",(m+1)*maxlcm);
        for(i=0;i<=m;i++)
            printf(" %I64d",f[i][0]);
        printf(" 0\n");
    }
    return 0;
}