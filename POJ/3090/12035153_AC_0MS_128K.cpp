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
const int N=1010;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7,STA=8000010;
//const LL LNF=1LL<<60;
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


int T,n;
int phi[N],prime[N],sum[N];
int cnt;
void phitable(int n)
{
    int i,j;
    //Init phi[N],prime[N],全局变量初始为0
    cnt=0;phi[1]=1;
    for(i=2;i<=n;i++){
        if(!phi[i]){
            prime[cnt++]=i;  //prime[i]=1;为素数表
            phi[i]=i-1;
        }
        for(j=0;j<cnt && i*prime[j]<=n;j++){
            if(i%prime[j])
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            else {phi[i*prime[j]]=phi[i]*prime[j];break;}
        }
    }
    for(i=1;i<n;i++)sum[i]=sum[i-1]+phi[i];
}

int main(){
 //   freopen("in.txt","r",stdin);
    int i,j,ca=1;
    LL ans;
    phitable(1001);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d %d %d\n",ca++,n,sum[n]<<1|1);
    }
    return 0;
}