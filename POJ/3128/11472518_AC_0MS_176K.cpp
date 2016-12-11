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
const int N=30,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;

char s[N],vis[N];
int T;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,u,cnt[N],ok;
    scanf("%d",&T);
    while(T--)
    {
        mem(vis,0);
        mem(cnt,0);
        scanf("%s",s);
        for(i=0;i<26;i++)s[i]-='A';
        for(i=0;i<26;i++){
            if(!vis[i]){
                u=i;j=0;
                while(!vis[u]){
                    vis[u]=1;
                    j++;
                    u=s[u];
                }
                if(!(j&1))cnt[j]++;
            }
        }
        for(i=0,ok=1;i<N;i++)
            if(cnt[i]&1){ok=0;break;}

        printf("%s\n",ok?"Yes":"No");
    }
    return 0;
}