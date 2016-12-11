#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<iostream>
//#include<string>
#include<algorithm>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<map>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=10010,INF=0x3f3f3f3f,MOD=60007,STA=1000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=100000000000;

int num[N],c[N],ma[N*10],vis[N],minu[N],cnt[N],s[N];
int n;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,u,ans,k,t,minc;
    while(~scanf("%d",&n))
    {
        ans=k=0;
        minc=INF;
        mem(vis,0);
        for(i=1;i<=n;i++){
            scanf("%d",&num[i]);
            c[i]=num[i];
        }
        sort(c+1,c+n+1);
        for(i=1;i<=n;i++)
            ma[c[i]]=i;

        for(i=1;i<=n;i++){
            if(!vis[i]){
                minu[k]=INF;
                cnt[k]=s[k]=0;
                u=i;
                while(!vis[u]){
                    vis[u]=1;
                    minu[k]=Min(minu[k],c[u]);
                    minc=Min(minc,c[u]);
                    s[k]+=c[u];
                    cnt[k]++;
                    u=ma[num[u]];
                }
                s[k]=s[k]+(cnt[k]-2)*minu[k];
                k++;
            }
        }
        for(i=0;i<k;i++){
            ans+=Min(s[i],s[i]+2*(minu[i]+minc)-(cnt[i]-1)*(minu[i]-minc));
        }

        printf("%d\n",ans);
    }
    return 0;
}