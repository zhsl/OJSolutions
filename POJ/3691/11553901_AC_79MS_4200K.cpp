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
#include<set>
using namespace std;
//define
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
//typedef
typedef __int64 LL;
typedef unsigned __int64 ULL;
//const
const int N=1010;
const int INF=0x3f3f3f3f;
const int MOD=100000,STA=8000010;
const LL LNF=1LL<<60;
const double EPS=1e-8;
const double OO=1e15;
//Daily Use ...
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

char s[N];
int idx[100];
int ch[N][4];
int val[N],f[N],dp[N][N],sta[N],ma[N];
int sz,n,cnt;

void init(){sz=1;mem(ch[0],0);}

void insert(char *s,int v){
    int i,len=strlen(s),id,u=0;
    for(i=0;i<len;i++){
        id=idx[s[i]];
        if(!ch[u][id]){
            mem(ch[sz],0);
            val[sz]=0;
            ch[u][id]=sz++;
        }
        u=ch[u][id];
    }
    val[u]=v;
}

void getFail()
{
    int c,u,r;
    queue<int> q;
    f[0]=0;
    ma[0]=0;sta[0]=cnt++;
    for(c=0;c<4;c++){
        u=ch[0][c];
        if(u){
            if(!val[u])ma[u]=cnt;sta[cnt++]=u;
            f[u]=0;
            q.push(u);
        }
    }
    while(!q.empty()){
        r=q.front();q.pop();
        for(c=0;c<4;c++){
            u=ch[r][c];
            if(!u){
                ch[r][c]=ch[f[r]][c];
                continue;
            }
            q.push(u);
            f[u]=ch[f[r]][c];
            if(val[r] || val[f[u]])val[u]=1;
            if(!val[u]){ma[u]=cnt;sta[cnt++]=u;}
        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,t,c,test=1,ans,len,ok,id,u;
    char p[23];
    idx['A']=0;idx['C']=1;idx['T']=2,idx['G']=3;
    while(~scanf("%d",&n) && n)
    {
        init();
        for(i=0;i<n;i++){
            scanf("%s",p);
            insert(p,1);
        }
        scanf("%s",s);
        len=strlen(s);

        cnt=0;
        mem(dp,INF);
        dp[0][0]=0;
        getFail();
        for(i=0;i<len;i++){
            ok=0;
            id=idx[s[i]];
            for(j=0;j<cnt;j++){
                if(dp[i][j]==INF)continue;
                for(c=0;c<4;c++){
                    u=ch[sta[j]][c];
                    t=(c!=id);
                    if(!val[u]){
                        ok=1;
                        dp[i+1][ma[u]]=Min(dp[i+1][ma[u]],dp[i][j]+t);
                    }
                }
            }
            /*
            for(int q=0;q<cnt;q++)
                printf("%d ",dp[i+1][q]);
            putchar('\n');
            */
            if(!ok)break;
        }

        if(ok){
            ans=INF;
            for(i=0;i<cnt;i++){
                ans=Min(ans,dp[len][i]);
            }
        }
        else ans=-1;

        printf("Case %d: %d\n",test++,ans);
    }
    return 0;
}