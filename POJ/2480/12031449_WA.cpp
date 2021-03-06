//STATUS:C++_AC_828MS_11284KB
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
//#include <map>
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
const int N=110;
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

LL p[N][2];
LL ans,n,cnt;

void dfs(LL d,LL phi)
{
    if(d==cnt){
        ans+=phi;
        return ;
    }
    dfs(d+1,phi);
    phi=phi/p[d][0]*(p[d][0]-1);
    for(int i=1;i<=p[d][1];i++)
        dfs(d+1,phi);
}

int main(){
 //   freopen("in.txt","r",stdin);
    int i,j,la;
    LL t;
    scanf("%I64d",&n);
    cnt=0;
    for(t=n,i=2;i*i<=t;i++){
        if(t%i==0){
            p[cnt][0]=i;
            while(t%i==0){
                p[cnt][1]++;
                t/=i;
            }
            cnt++;
        }
    }
    if(t)p[cnt][0]=t,p[cnt][1]=1,cnt++;

    ans=0;
    dfs(0,n);

    printf("%I64d\n",ans);
    return 0;
}