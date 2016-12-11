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
const int N=1010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;

int T[2][N],vis[N],C[N];
int n,s;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,p,u,d;
    while(~scanf("%d%d",&n,&s))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&T[0][i]);

        p=1;
        while(s--){
            mem(vis,0);
            for(i=1;i<=n;i++){
                if(!vis[i]){
                    mem(vis,0);
                    u=i;k=0;
                    while(!vis[u]){
                        vis[u]=1;
                        C[k++]=u;
                        u=T[!p][u];
                    }
                    d=(k+1)/2;
                    for(j=0;j<k;j++){
                        T[p][C[j]]=C[(j+d)%k];
                    }
                }
            }
            p=!p;
        }

        p=!p;
        for(i=1;i<=n;i++)
            printf("%d\n",T[p][i]);
    }
    return 0;
}