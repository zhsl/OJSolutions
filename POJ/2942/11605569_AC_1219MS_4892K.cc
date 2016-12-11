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
}e[N*N];
bool iscut[N];
int first[N],next[N*N],low[N],pre[N],bccno[N],vis[N],color[N],ma[N][N];
int n,m,mt,dfs_clock,bcnt;
vector<int> bcc[N];
stack<Edge> s;

void adde(int a,int b)
{
    e[mt].u=a;e[mt].v=b;
    next[mt]=first[a];first[a]=mt++;
    e[mt].u=b;e[mt].v=a;
    next[mt]=first[b];first[b]=mt++;
}

bool bipartite(int u,int a)
{
    int i,v;
    for(i=first[u];i!=-1;i=next[i]){
        v=e[i].v;
        if(bccno[u]!=a)continue;
        if(color[v]==color[u])return false;
        if(!color[v]){
            color[v]=3-color[u];
            if(!bipartite(v,a))return false;
        }
    }
    return true;
}

void dfs(int u,int fa)
{
    int i,j,v,child=0;
    pre[u]=low[u]=++dfs_clock;
    for(i=first[u];i!=-1;i=next[i]){
        child++;
        v=e[i].v;
        if(!pre[v]){
            s.push({u,v});
            dfs(v,u);
            low[u]=Min(low[u],low[v]);
            if(low[v]>=pre[u]){
                iscut[u]=true;
                Edge x;x.u=-1;
                bcnt++;bcc[bcnt].clear();
                while(x.u!=u || x.v!=v){
                    x=s.top();s.pop();
                    if(bccno[x.u]!=bcnt){bcc[bcnt].push_back(x.u);bccno[x.u]=bcnt;}
                    if(bccno[x.v]!=bcnt){bcc[bcnt].push_back(x.v);bccno[x.v]=bcnt;}
                }
            }
        }
        else if(v!=fa && pre[v]<pre[u]){
            s.push({u,v});
            low[u]=Min(low[u],pre[v]);
        }
    }
    if(fa==-1 && child==1)iscut[u]=false;
}

void find_bcc()
{
    int i,j;
    bcnt=dfs_clock=0;mem(pre,0);
    mem(bccno,0);mem(iscut,0);
    for(i=1;i<=n;i++){
        if(!pre[i])dfs(i,-1);
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,ans;
    while(~scanf("%d%d",&n,&m) && (n ||m ))
    {
        mem(ma,0);
        while(m--){
            scanf("%d%d",&a,&b);
            ma[a][b]=ma[b][a]=1;
        }
        mt=0;
        mem(first,-1);
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(!ma[i][j])adde(i,j);
            }
        }

        find_bcc();
        /*
        printf(" %d\n",bcnt);
        for(i=1;i<=bcnt;i++){
            for(j=0;j<bcc[i].size();j++)
                printf("%d ",bcc[i][j]);
            putchar('\n');
        }
        */
        mem(vis,0);
        for(i=1;i<=bcnt;i++){
            for(j=0;j<bcc[i].size();j++)bccno[bcc[i][j]]=i;
            mem(color,0);
            color[bcc[i][0]]=1;
            if(!bipartite(bcc[i][0],i)){
                for(j=0;j<bcc[i].size();j++)vis[bcc[i][j]]=1;
            }
        }
        ans=n;
        for(i=1;i<=n;i++)ans-=vis[i];

        printf("%d\n",ans);
    }
    return 0;
}