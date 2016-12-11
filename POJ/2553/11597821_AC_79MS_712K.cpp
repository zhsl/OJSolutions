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
const int N=5010;
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

int pre[N],low[N],sccno[N],ans[N],vis[N];
int n,m,dfs_clock,k,scnt;
vector<int> g[N];
stack<int> s;

int dfs(int u)
{
    pre[u]=++dfs_clock;
    int i,v,ok=1;
    low[u]=pre[u];
    s.push(u);
    for(i=0;i<g[u].size();i++){
        v=g[u][i];
        if(!pre[v]){
            dfs(v);
            low[u]=Min(low[u],low[v]);
        }
        else if(!sccno[v]){
            low[u]=Min(low[u],low[v]);
        }
    }
    if(low[u]==pre[u]){
        scnt++;
        int x=-1;
        while(x!=u){
            x=s.top(),s.pop();
            sccno[x]=scnt;
        }
    //    printf(" %d %d %d\n",u,k,ok);
    }
    return ok;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,ok;
    while(~scanf("%d%d",&n,&m) && n)
    {
        for(i=1;i<=n;i++)g[i].clear();
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
        }

        mem(pre,0);mem(sccno,0);
        dfs_clock=scnt=0;
        for(i=1;i<=n;i++){
            if(!pre[i])dfs(i);
        }
        for(i=1;i<=scnt;i++)vis[i]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<g[i].size();j++){
                if(sccno[g[i][j]]!=sccno[i]){
                    vis[sccno[i]]=0;
                    break;
                }
            }
        }
        k=0;
        for(i=1;i<=n;i++){
            if(vis[sccno[i]])ans[k++]=i;
        }
        sort(ans,ans+k);
        printf("%d",ans[0]);
        for(i=1;i<k;i++)
            printf(" %d",ans[i]);
        putchar('\n');
    }
    return 0;
}