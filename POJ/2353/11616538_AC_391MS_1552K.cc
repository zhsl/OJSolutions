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
const int N=510,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

LL f[110][N],prel[N][2],prer[N][2];
int path[110][N],list[110][N];
int n,m;

int printpath(int cur,int w)
{
    if(cur==1){
        printf("%d\n",w);
        return w;
    }
    int i,la;
    la=printpath(cur-1,path[cur][w]);
    if(cur==n){printf("%d\n",w);return 0;}
    if(la<=w)for(i=la;i<=w;i++)printf("%d\n",i);
    else for(i=la;i>=w;i--)printf("%d\n",i);
    return w;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,w;
    LL sum[N],t,ans;
    while(~scanf("%d%d",&n,&m))
    {
        mem(f,INF);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)
                scanf("%d",&list[i][j]);
        }
        sum[0]=0;
        prel[0][0]=prer[m+1][0]=DNF;
        for(i=1;i<=m;i++)f[1][i]=list[1][i];
        for(i=2;i<=n;i++){
            for(j=1;j<=m;j++){
                sum[j]=sum[j-1]+list[i][j];
                prel[j][0]=prel[j-1][0];
                prel[j][1]=prel[j-1][1];
                if((t=f[i-1][j]-sum[j-1])<prel[j][0])
                    prel[j][0]=t,prel[j][1]=j;
            }
            for(j=m;j>=1;j--){
                prer[j][0]=prer[j+1][0];
                prer[j][1]=prer[j+1][1];
                if((t=f[i-1][j]+sum[j])<prer[j][0])
                    prer[j][0]=t,prer[j][1]=j;
            }
            for(j=1;j<=m;j++){
                if(prel[j][0]+sum[j]<prer[j][0]-sum[j-1]){
                    f[i][j]=prel[j][0]+sum[j];
                    path[i][j]=prel[j][1];
                }
                else {
                    f[i][j]=prer[j][0]-sum[j-1];
                    path[i][j]=prer[j][1];
                }
            }
        }

        for(i=1,ans=DNF;i<=m;i++)if(f[n][i]<ans)ans=f[n][i],w=i;
        printpath(n,w);
    }
    return 0;
}