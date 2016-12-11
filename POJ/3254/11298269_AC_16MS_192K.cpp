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
const int N=12,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

int map[N][N],f[2][(1<<N)+10];
int n,m;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,p,ans;
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        mem(f,0);f[0][0]=p=1;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&map[i][j]);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++,mem(f[p=!p],0)){
                for(k=0;k<(1<<m);k++){
                    if(k&(1<<j))
                        f[p][k&~(1<<j)]=(f[p][k&~(1<<j)]+f[!p][k])%MOD;
                    else {
                        f[p][k]=(f[p][k]+f[!p][k])%MOD;
                        if((j && !(k&(1<<(j-1))) || !j ) && map[i][j])
                            f[p][k|(1<<j)]=(f[p][k|(1<<j)]+f[!p][k])%MOD;
                    }
                }
            }
        }
        p=!p;
        for(i=0;i<(1<<m);i++)
            ans=(ans+f[p][i])%MOD;

        printf("%d\n",ans);
    }
    return 0;
}