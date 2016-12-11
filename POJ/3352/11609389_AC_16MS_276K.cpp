#include <functional>
#include <algorithm>
#include <iostream>
//#include <ext/rope>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
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
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
//Daily Use ...
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

struct Edge{
    int u,v;
}e[N*2];
//bool iscut[N];
int first[N],next[N*2],pre[N],low[N],bccno[N],cnt[N];
int n,m,mt,bcnt,dfs_clock;
stack<int> s;

void adde(int a,int b)
{
    e[mt].u=a;e[mt].v=b;
    next[mt]=first[a];first[a]=mt++;
    e[mt].u=b;e[mt].v=a;
    next[mt]=first[b];first[b]=mt++;
}

void dfs(int u,int fa)
{
    int i,v;
    pre[u]=low[u]=++dfs_clock;
    s.push(u);
    for(i=first[u];i!=-1;i=next[i]){
        v=e[i].v;
        if(!pre[v]){
            dfs(v,u);
            low[u]=Min(low[u],low[v]);
          //  if(low[v]>pre[u])iscut[i]=true;
        }
        else if(v!=fa && pre[v]<pre[u]){
            low[u]=Min(low[u],pre[v]);
        }
    }
    if(low[u]==pre[u]){
        int x=-1;
        bcnt++;
        while(x!=u){
            x=s.top();s.pop();
            bccno[x]=bcnt;
        }
    }
}

void find_bcc()
{
    int i;
    bcnt=dfs_clock=0;//mem(iscut,0);
    mem(pre,0);mem(bccno,0);
    for(i=1;i<=n;i++){
        if(!pre[i])dfs(i,-1);
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,ans,t;
    while(~scanf("%d%d",&n,&m))
    {
        mt=0;
        mem(first,-1);
        while(m--){
            scanf("%d%d",&a,&b);
            adde(a,b);
        }

        find_bcc();
        ans=0;
        if(bcnt>1){
            mem(cnt,0);
            for(i=0;i<mt;i+=2){
                if(bccno[e[i].u]!=bccno[e[i].v]){
                    cnt[bccno[e[i].u]]++;
                    cnt[bccno[e[i].v]]++;
                }
            }
            for(i=1;i<=bcnt;i++){
                if(cnt[i]<=1)ans++;
            }
        }

        printf("%d\n",(ans+1)/2);
    }
    return 0;
}