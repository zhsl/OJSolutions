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
typedef __int64 LL;
typedef unsigned __int64 ULL;
//const
const int N=310;
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

int num[N],q[N];
int n;
LL m,f[N];
multiset<int> sbt;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,l,r,p,ok;
    LL sum;
    while(~scanf("%d%I64d",&n,&m))
    {
        l=sum=0;r=-1;
        sbt.clear();
        ok=1;
        for(i=p=1;i<=n;i++){
            scanf("%d",&num[i]);
            sum+=num[i];
            while(sum>m)sum-=num[p++];
            if(p>i){ok=0;break;}
            while(l<=r && num[i]>=num[q[r]]){
                if(l<r)sbt.erase(f[q[r-1]]+num[q[r]]);
                r--;
            }
            q[++r]=i;
            if(l<r)sbt.insert(f[q[r-1]]+num[q[r]]);
            while(q[l]<p){
                if(l<r)sbt.erase(f[q[l]]+num[q[l+1]]);
                l++;
            }
            f[i]=f[p-1]+num[q[l]];
            if(l<r)f[i]=Min(f[i],(LL)*sbt.begin());
        }
        for(;i<=n;i++)
            scanf("%d",&j);

        printf("%I64d\n",ok?f[n]:-1);
    }
    return 0;
}
