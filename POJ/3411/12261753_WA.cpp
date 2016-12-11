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
//#pragma comment(linker,"/STACK:102400000,102400000")
//using namespace __gnu_cxx;
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
const int N=11,M=200010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
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

struct Node{
    int sta,u,d;
    Node(){};
    Node(int _sta,int _u,int _d){sta=_sta,u=_u,d=_d;}
    bool operator < (const Node& a)const {
        return d<a.d;
    }
};

int d[N][N*N*N],w[N][N][2],ci[N][N];
int n,m;

int Dijkstra()
{
    int i,j,t,sta,ret;
    priority_queue<Node> q;
    Node u;
    mem(d,INF);d[1][1]=0;
    q.push(Node(1,1,0));
    while(!q.empty()){
        u=q.top();q.pop();
        if(u.d!=d[u.u][u.sta])continue;
        for(i=1;i<=n;i++){
            if(w[u.u][i][0]==-1)continue;
            t=u.d+((u.sta&(1<<ci[u.u][i]))?w[u.u][i][0]:w[u.u][i][1]);
            sta=u.sta|(1<<(i-1));
            if(t<d[i][sta]){
                d[i][sta]=t;
                q.push(Node(sta,i,t));
            }
        }
    }
    ret=INF;
    for(i=0;i<(1<<n);i++)ret=Min(ret,d[n][i]);
    return ret;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,c,p,r;
    while(~scanf("%d%d",&n,&m))
    {
        mem(w,-1);
        for(i=0;i<m;i++){
            scanf("%d%d%d%d%d",&a,&b,&c,&p,&r);
            ci[a][b]=c-1;
            w[a][b][0]=p;w[a][b][1]=r;
        }

        printf("%d\n",Dijkstra());
    }
    return 0;
}