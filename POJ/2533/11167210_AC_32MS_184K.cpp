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
const int N=1010,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int num[N],w[N],f[N];
int n;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    while(~scanf("%d",&n))
    {
        ans=f[0]=1;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        for(i=1;i<n;i++){
            f[i]=1;
            for(j=0;j<i;j++)
                if(num[j]<num[i])
                    f[i]=Max(f[i],f[j]+1);
            if(f[i]>ans)ans=f[i];
        }

        printf("%d\n",ans);
    }
    return 0;
}