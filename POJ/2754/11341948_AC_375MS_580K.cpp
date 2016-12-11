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
const int N=210,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

int f[N*25*20],pa[N],m[N],l[N],up[N];
int n,rp,rm;

void zo(int v,int w)
{
    int j;
    for(j=rm;j>=v;j--){
        if(f[j-v]>=0)
        f[j]=Max(f[j],f[j-v]+w);
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k;
    while(~scanf("%d",&n))
    {
        mem(f,-1);
        for(i=rm=rp=0;i<n;i++){
            scanf("%d%d%d%d",&pa[i],&m[i],&l[i],&up[i]);
            rp+=l[i]*pa[i];
            rm-=l[i]*m[i];
            up[i]-=l[i];
        }
        f[0]=0;
        for(i=0;i<n;i++){
            for(k=1;up[i]>k;up[i]-=k,k<<=1){
                zo(k*m[i],k*pa[i]);
            }
            if(up[i])zo(up[i]*m[i],up[i]*pa[i]);
        }

        printf("%d\n",f[rm]+rp);
    }
    return 0;
}