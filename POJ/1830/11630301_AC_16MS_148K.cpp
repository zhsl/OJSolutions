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
const int N=33;
const int INF=0x3f3f3f3f;
//const int MOD=100000,STA=8000010;
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

int A[N][N];
int T,n;

int gauss(int n)
{
    int i,j,k,cnt,ok;
    for(i=0;i<n;i++){
        if(!A[i][i]){
            for(j=i+1;j<n;j++){
                if(A[j][i]){
                    for(k=0;k<=n;k++)swap(A[i][k],A[j][k]);
                    break;
                }
            }
        }
        for(j=i+1;j<n;j++){
            if(A[j][i]){
                for(k=i;k<=n;k++)
                    A[j][k]^=A[i][k];
            }
        }
    }
    for(i=n-1,cnt=0;i>=0;i--){
        ok=1;
        for(j=i;j<n;j++)if(A[i][j]){ok=0;break;}
        if(ok && A[i][n])return 0;
        else if(ok)cnt++;
    }
    return 1<<cnt;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,t,a,b,ans;
    scanf("%d",&T);
    while(T--)
    {
        mem(A,0);
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&A[i][n]);
        for(i=0;i<n;i++){
            scanf("%d",&t);
            A[i][n]^=t;
        }
        for(i=0;i<n;i++)A[i][i]=1;
        while(scanf("%d%d",&a,&b) && (a || b))
            A[b-1][a-1]=1;

        ans=gauss(n);

        if(ans)printf("%d\n",ans);
        else printf("Oh,it's impossible~!!\n");
    }
    return 0;
}