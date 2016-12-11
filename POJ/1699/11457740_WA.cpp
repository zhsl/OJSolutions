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
const int N=11,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const double DNF=1e13;

char s[N][22];
int f[2][1<<N][11],len[N],g[N][N],next[2][1<<N],cnt[2],vis[1<<N];
int T,n;

void getg()
{
    int i,j,k,p;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<=len[i];k++){
                for(p=k;p<len[i] && p-k<len[j];p++)
                    if(s[i][p]!=s[j][p-k])break;
                if(p==len[i] || p-k==len[j]){
                    g[i][j]=Min(len[i]-k,len[j]);
                    break;
                }
            }
        }
    }
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,p,st1,k,r,st2,ans,rt;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",s[i]);
            len[i]=strlen(s[i]);
        }
        getg();

        mem(cnt,0);
        mem(vis,0);
        for(i=0;i<n;i++){
            next[0][cnt[0]]=1<<i;
            f[0][1<<i][i]=len[i];
            cnt[0]++;
        }
        mem(f[p=1],INF);
        for(i=1;i<n;i++){
            for(k=0;k<cnt[!p];k++){
                st1=next[!p][k];
                for(r=0;r<n;r++){
                    if(st1&(1<<r)){
                        for(j=0;j<n;j++){
                            if(st1&(1<<j))continue;
                            st2=st1|(1<<j);
                            if(!vis[st2]){
                                vis[st2]=1;
                                next[p][cnt[p]++]=st2;
                            }
                         //   if(g[r][j]==len[j])rt=r;
                        //    else rt=j;
                            f[p][st2][rt]=Min(f[p][st2][rt],f[!p][st1][r]+len[j]-g[r][j]);
                        }
                    }
                }
            }
            mem(vis,0);
            cnt[p=!p]=0;
            mem(f[p],INF);
        }

        ans=INF;
        k=(1<<n)-1;
        for(i=0;i<n;i++)
            ans=Min(ans,f[!p][k][i]);
        printf("%d\n",ans);
    }
    return 0;
}

