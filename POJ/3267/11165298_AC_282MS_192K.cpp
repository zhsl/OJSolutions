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
const int N=610,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

char s[N][30],tx[N];
int f[N],len[N],w[N];
int n,m;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k;
    while(~scanf("%d%d",&n,&m))
    {
        f[0]=0;
        scanf("%s",tx);
        for(i=0;i<n;i++){
            scanf("%s",s[i]);
            len[i]=strlen(s[i]);
        }
        for(i=1;i<=m;i++){
            f[i]=f[i-1];
            for(k=0;k<n;k++)w[k]=len[k]-1;
            for(j=i-1;j>=0;j--){
                for(k=0;k<n;k++){
                    if(tx[j]==s[k][w[k]])w[k]--;
                    if(w[k]<0)f[i]=Max(f[i],f[j]+len[k]);
                }
            }
        }

        printf("%d\n",m-f[m]);
    }
    return 0;
}