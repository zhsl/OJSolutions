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
//using namespace __gnu_cxx;
//define
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
//typedef
typedef long long LL;
typedef unsigned long long ULL;
//const
const int N=210;
const int INF=0x3f3f3f3f;
const int MOD=100000,STA=8000010;
const LL LNF=1LL<<60;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//Daily Use ...
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

struct Edge{
    int u,v;
}e[N*N];
int first[N],next[N*N],vis[N],out[N],d[N],ans[N];
int T,n,m,mt;

void adde(int a,int b)
{
    e[mt].u=a;e[mt].v=b;
    next[mt]=first[a],first[a]=mt++;
}

int dfs(int u)
{
    if(d[u]!=INF)return d[u];
    int i;
    d[u]=u;
    for(i=first[u];i!=-1;i=next[i]){
        d[u]=Min(d[u],dfs(e[i].v));
    }
    return d[u];
}

int topo()
{
    int i,j,k,low1,low2,ok;
    mem(out,0);
    for(k=0;k<n;k++){
        mem(vis,0);
        for(i=1;i<=n;i++){
            for(j=first[i];j!=-1;j=next[j]){
                vis[e[j].v]=1;
            }
        }
        low1=n+1;ok=0;
        for(i=1;i<=n;i++){
            if(vis[i] || out[i])continue;
            ok=1;
            if(d[i]<low1 || (d[i]==low1 && i<low2)){
                low1=d[i];low2=i;
            }
        }
        if(ok==0)return 0;
        ans[k]=low2;
        out[low2]=1;
        first[low2]=-1;
    }
    return 1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        mem(first,-1);mt=0;
        while(m--){
            scanf("%d%d",&a,&b);
            adde(a,b);
        }
        mem(d,INF);
        for(i=1;i<=n;i++)
            if(d[i]==INF)dfs(i);

        if(topo()){
            printf("%d",ans[0]);
            for(i=1;i<n;i++)
                printf(" %d",ans[i]);
        }
        else printf("-1");
        putchar('\n');
    }
    return 0;
}