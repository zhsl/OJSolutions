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
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=210,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

int f[N*10],w[N][N];
int nt,n,m,s,t;
struct Matrix{
    int ma[N][N];
    Matrix friend operator * (const Matrix a,const Matrix b){
        Matrix ret;
        mem(ret.ma,0x3f);
        int i,j,k;
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    if(a.ma[i][k]+b.ma[k][j]<ret.ma[i][j])
                        ret.ma[i][j]=a.ma[i][k]+b.ma[k][j];
        return ret;
    }
}mta,mtb;

int pow(int k)
{
    mem(mtb.ma,0x3f);
    for(int i=0;i<n;i++)mtb.ma[i][i]=0;
    for(;k;k>>=1){
        if(k&1)mtb=mtb*mta;
        mta=mta*mta;
    }
    return mtb.ma[f[s]][f[t]];
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,a,b,c;
    while(~scanf("%d%d%d%d",&nt,&m,&s,&t))
    {
        n=0;
        mem(f,-1);
        mem(mta.ma,0x3f);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&c,&a,&b);
            if(f[a]==-1)f[a]=n++;
            if(f[b]==-1)f[b]=n++;
            mta.ma[f[a]][f[b]]=mta.ma[f[b]][f[a]]=Min(mta.ma[f[a]][f[b]],c);
        }

        printf("%d\n",pow(nt));
    }
    return 0;
}