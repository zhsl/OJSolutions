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
const int N=50010;
const int INF=0x3f3f3f3f;
//const LL MOD=1000000007,STA=8000010;
const LL LNF=1LL<<55;
const double EPS=1e-9;
const double OO=1e50;
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

double x[5],low[32],hig[32];
int n;

int main(){
 //   freopen("in.txt","r",stdin);
    int i,j,k;
    double ans,sum;
    while(~scanf("%d",&n))
    {
        for(i=0;i<32;i++){
            low[i]=OO;
            hig[i]=-OO;
        }
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf%lf",&x[0],&x[1],&x[2],&x[3],&x[4]);
            for(j=0;j<32;j++){
                sum=0;
                for(k=0;k<5;k++){
                    sum+=(j&(1<<k)?x[k]:-x[k]);
                }
                low[j]=Min(low[j],sum);
                hig[j]=Max(hig[j],sum);
            }
        }
        ans=0;
        for(i=0;i<32;i++){
            ans=Max(ans,hig[i]-low[i]);
        }

        printf("%.2lf\n",ans);
    }
    return 0;
}