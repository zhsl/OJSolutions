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
const int N=10010;
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
}e[N*5];
int first[N],next[N*5],pre[N],sccno[N],low[N],vis[N],p[N];
int n,m,mt,dfs_clock,scnt;
stack<int> s;

int find(int x){return p[x]==x?x:p[x]=find(p[x]);}

void adde(int a,int b)
{
    e[mt].u=a;e[mt].v=b;
    next[mt]=first[a],first[a]=mt++;
}

void dfs(int u)
{
    int i,j,v;
    pre[u]=low[u]=++dfs_clock;
    s.push(u);
    for(i=first[u];i!=-1;i=next[i]){
        v=e[i].v;
        if(!pre[v]){
            dfs(v);
            low[u]=Min(low[u],low[v]);
        }
        else if(!sccno[v]){
            low[u]=Min(low[u],low[v]);
        }
    }
    if(low[u]==pre[u]){
        int x=-1;
        scnt++;
        while(x!=u){
            x=s.top();s.pop();
            sccno[x]=scnt;
        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,ans,x,y,ok;
    while(~scanf("%d%d",&n,&m))
    {
        mem(first,-1);mt=0;
        for(i=1;i<=n;i++)p[i]=i;
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            x=find(a);y=find(b);
            if(x!=y)p[y]=p[x];
            adde(a,b);
        }
        ok=0;
        for(i=1;i<=n;i++){
            if(p[i]==i)ok++;
            if(ok>=2)break;
        }
        ans=0;
        if(ok==1){
            mem(pre,0);mem(sccno,0);
            scnt=dfs_clock=0;
            for(i=1;i<=n;i++){
                if(!pre[i])dfs(i);
            }
            for(i=1;i<=scnt;i++)vis[i]=1;
            for(i=0;i<mt;i++){
                if(sccno[e[i].u]!=sccno[e[i].v]){
                    vis[sccno[e[i].u]]=0;
                }
            }
            ok=0;
            for(i=1;i<=scnt;i++){
                ok+=vis[i];
                if(ok>=2){ok=0;break;}
            }
            if(ok){
                for(i=1;i<=n;i++){
                    if(vis[sccno[i]])ans++;
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}