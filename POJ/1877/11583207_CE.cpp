#include <functional>
#include <algorithm>
#include <iostream>
#include <ext/rope>
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
typedef long long LL;
typedef unsigned long long ULL;
//const
const int N=1010;
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

double ma[N];
double v;
int n,m;


int main()
{
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int i,j,cnt,k=1;
    double h,vt,t[N];
    while(~scanf("%d%d",&n,&m) && (n || m) )
    {
        n*=m;
        for(i=0;i<n;i++)
                scanf("%lf",&ma[i]);
        scanf("%lf",&v);

        sort(ma,ma+n);
        for(i=0;i<n;i++)t[i]=ma[i+1]-ma[i];
        for(i=0;i<n-1;i++){
            vt=(i+1)*100*t[i];
            if(vt<=v)v-=vt;
            else break;
        }
        cnt=i+1;
        h=ma[i]+v/(cnt*100);

        printf("Region %d\n",k++);
        printf("Water level is %.2lf meters.\n",h);
        printf("%.2lf percent of the region is under water.\n\n",(double)cnt*100/n);
    }
    return 0;
}