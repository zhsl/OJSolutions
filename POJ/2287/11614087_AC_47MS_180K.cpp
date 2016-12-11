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
const int MOD=256,STA=8000010;
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
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

int x[N],y[N];
int n;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans,lx,rx,ly,ry;
    while(~scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&x[i]);
        for(i=0;i<n;i++)
            scanf("%d",&y[i]);

        sort(x,x+n);
        sort(y,y+n);
        lx=ly=ans=0;rx=ry=n-1;
        while(lx<=rx){
            if(x[lx]>y[ly]){
                lx++,ly++;
                ans+=200;
            }
            else if(x[lx]<y[ly]){
                lx++,ry--;
                ans-=200;
            }
            else {
                if(x[rx]>y[ry]){
                    rx--,ry--;
                    ans+=200;
                }
                else {
                    if(x[lx]<y[ry])ans-=200;
                    lx++,ry--;
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}