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
const int N=510;
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

int w[N][N];
int v[N], dis[N];
bool vis[N];
int n,m;

int Stoer_Wagner(int n){
    int i, j, res = INF;
    for(i = 0; i < n; i ++)
        v[i] = i;
    while(n > 1){
        int k = 1, pre = 0;
        for(i = 1; i < n; i ++){
            dis[v[i]] = w[v[0]][v[i]];
            if(dis[v[i]] > dis[v[k]])
                k = i;
        }
        memset(vis, 0, sizeof(vis));
        vis[v[0]] = true;
        for(i = 1; i < n; i ++){
            if(i == n-1){
                res = min(res, dis[v[k]]);
                for(j = 0; j < n; j ++){
                    w[v[pre]][v[j]] += w[v[j]][v[k]];
                    w[v[j]][v[pre]] += w[v[j]][v[k]];
                }
                v[k] = v[-- n];
            }
            vis[v[k]] = true;
            pre = k;
            k = -1;
            for(j = 1; j < n; j ++)
                if(!vis[v[j]]){
                    dis[v[j]] += w[v[pre]][v[j]];
                    if(k == -1 || dis[v[k]] < dis[v[j]])
                        k = j;
                }
        }
    }
    return res;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,c;
    while(~scanf("%d%d",&n,&m))
    {
        mem(w,0);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            w[a][b]+=c;
            w[b][a]+=c;
        }

        printf("%d\n",Stoer_Wagner(n));
    }
    return 0;
}