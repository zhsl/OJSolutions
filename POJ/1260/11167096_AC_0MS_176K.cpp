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
const int N=110,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int num[N],w[N],f[N];
int T,n;

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,k,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        f[0]=0;
        for(i=1;i<=n;i++)
            scanf("%d%d",&num[i],&w[i]);
        for(i=1;i<=n;i++){
            f[i]=INF;
            for(j=0;j<i;j++){
                for(t=10,k=j+1;k<=i;k++)
                    t+=num[k];
                f[i]=Min(f[i],f[j]+t*w[i]);
            }
        }

        printf("%d\n",f[n]);
    }
    return 0;
}