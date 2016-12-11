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
const int N=25,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int c[N],g[N],f[N][15010];
int n,m;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k;
    while(~scanf("%d%d",&n,&m))
    {
        mem(f,0);
        f[0][7500]=1;
        for(i=1;i<=n;i++)
            scanf("%d",&c[i]);
        for(i=1;i<=m;i++)
            scanf("%d",&g[i]);
        for(i=1;i<=m;i++){
            for(j=0;j<=15000;j++){
                if(f[i-1][j]){
                    for(k=1;k<=n;k++)
                        f[i][j+c[k]*g[i]]+=f[i-1][j];
                }
            }
        }

        printf("%d\n",f[m][7500]);
    }
    return 0;
}