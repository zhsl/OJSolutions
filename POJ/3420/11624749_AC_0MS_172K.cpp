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
const int N=20;
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

const int size=6;
LL ma[size][size]={
{1,1,0,1,1,1},
{1,0,0,0,1,0},
{0,0,0,1,0,0},
{1,0,1,0,0,0},
{1,1,0,0,0,0},
{1,0,0,0,0,0}
};
LL n,MOD;

struct Matrix{
    LL ma[size][size];
    Matrix friend operator * (const Matrix a,const Matrix b){
        Matrix ret;
        mem(ret.ma,0);
        int i,j,k;
        for(k=0;k<size;k++)
            for(i=0;i<size;i++)
                for(j=0;j<size;j++)
                    ret.ma[i][j]=(ret.ma[i][j]+a.ma[i][k]*b.ma[k][j])%MOD;
        return ret;
    }
}ans,mta;

void mutilpow(LL k)
{
    int i,j;
    mem(ans.ma,0);
    for(i=0;i<size;i++)
        ans.ma[i][i]=1;
    for(;k;k>>=1){
        if(k&1)ans=ans*mta;
        mta=mta*mta;
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%I64d%I64d",&n,&MOD) && (n||MOD))
    {
        for(i=0;i<size;i++){
            for(j=0;j<size;j++)
                mta.ma[i][j]=ma[i][j];
        }

        mutilpow(n);

        printf("%I64d\n",ans.ma[0][0]);
    }
    return 0;
}