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
#define LL long long
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=210,INF=0x3f3f3f3f,MOD=40001,STA=8000010;
const double DNF=1e13;

int c[N],f[N][N],vis[N];
int n,k,cnt;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,lens,r,t,u,w;
    char s[N],ans[N];
    while(~scanf("%d",&n) && n)
    {
        cnt=0;
        mem(vis,0);
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
            f[i][0]=0;
        }

        for(i=1;i<=n;i++){
            if(!vis[i]){
                f[cnt][0]=0;
                u=i;
                while(!vis[u]){
                    vis[u]=1;
                    f[cnt][++f[cnt][0]]=u;
                    u=c[u];
                }
                cnt++;
            }
        }

        while(scanf("%d",&k) && k){
            getchar();
            gets(s);
            lens=strlen(s);
            while(lens<n)s[lens++]=' ';
            s[lens]=0;
            for(i=0;i<cnt;i++){
                t=f[i][0];
                r=k%t;
                for(j=1;j<=t;j++){
                    w=((j+r)%t>0?(j+r)%t:t);
                    ans[f[i][w]-1]=s[f[i][j]-1];
                }
            }
            ans[n]=0;
            printf("%s\n",ans);
        }
        putchar('\n');
    }
    return 0;
}