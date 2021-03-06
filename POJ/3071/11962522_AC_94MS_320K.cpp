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
const int N=130;
const int INF=0x3f3f3f3f;
const LL MOD=1000000007,STA=8000010;
const LL LNF=1LL<<55;
const double EPS=1e-9;
const double OO=1e30;
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

double f[8][N],p[N][N];
int n;

void dfs(int l,int r,int d)
{
    if(l==r){f[d][l]=1;return;}
    int i,j,mid=(l+r)>>1;
    dfs(l,mid,d+1);
    dfs(mid+1,r,d+1);
    for(i=l;i<=mid;i++){
        f[d][i]=0;
        for(j=mid+1;j<=r;j++){
            f[d][i]+=f[d+1][i]*f[d+1][j]*p[i][j];
        }
    }
    for(i=mid+1;i<=r;i++){
        f[d][i]=0;
        for(j=l;j<=mid;j++){
            f[d][i]+=f[d+1][i]*f[d+1][j]*p[i][j];
        }
    }
}

int main(){
 //   freopen("in.txt","r",stdin);
    int i,j,k,tot;
    while(~scanf("%d",&n) && n!=-1)
    {
        tot=1<<n;
        for(i=0;i<tot;i++){
            for(j=0;j<tot;j++)
                scanf("%lf",&p[i][j]);
        }

        dfs(0,tot-1,0);
        double hig=0;
        int w;
        for(i=0;i<tot;i++){
            if(f[0][i]>hig){hig=f[0][i],w=i+1;}
        }
        printf("%d\n",w);
    }
    return 0;
}