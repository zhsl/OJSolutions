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
const int N=800010;
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

int num,f[N];
int T,n;

int binary(int l,int r,int tar)
{
    int mid;
    while(l<r){
        mid=(l+r)>>1;
        if(f[mid]>=tar)l=mid+1;
        else r=mid;
    }
    return l;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,l,r,k,ca=1;
    while(1){
        scanf("%d",&num);
        if(num==-1)break;
        l=1;r=2;
        f[1]=num;
        while(1){
            scanf("%d",&num);
            if(num==-1)break;
            k=binary(l,r,num);
            f[k]=num;
            r=Max(r,k+1);
        }

        printf("Test #%d:\n",ca++);
        printf("  maximum possible interceptions: %d\n",r-1);
    }
    return 0;
}