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
const int N=10010,INF=0x3f3f3f3f,MOD=40001,STA=8000010;
const double DNF=1e13;

int num[N],vis[N];
int T,n;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,cnt,u;
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        mem(vis,0);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);

        for(i=1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                u=i;
                while(!vis[u]){
                    vis[u]=1;
                    u=num[u];
                }
            }
        }

        printf("%d\n",n-cnt);
    }
    return 0;
}