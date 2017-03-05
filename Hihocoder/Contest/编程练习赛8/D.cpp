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
typedef long long LL;
typedef unsigned long long ULL;
//const
const int N=100010;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7,STA=8000010;
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


int n,m,k;

pii p[20];

int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=0;i<k;i++){
            scanf("%d%d",&p[i].first,&p[i].second);
        }

        LL ans=(LL)n*(n+1)/2*m*(m+1)/2;
        for(int i=1;i<(1<<k);i++){
            int cnt=0;
            pii lu=make_pair(n,m),rd=make_pair(1,1);
            for(int j=0;j<k;j++){
                if(!(i&(1<<j)))continue;
                lu.first=Min(lu.first, p[j].first);
                lu.second=Min(lu.second, p[j].second);
                rd.first=Max(rd.first, p[j].first);
                rd.second=Max(rd.second, p[j].second);
                cnt++;
            }
            ans+=(cnt&1?-1LL:1LL)*((LL)lu.first*lu.second*(n-rd.first+1)*(m-rd.second+1));
        }

        printf("%lld\n", ans);
    }

    return 0;
}

