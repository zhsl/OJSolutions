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
typedef long long LL;
typedef unsigned long long ULL;
//const
const int N=100000010;
const int INF=0x3f3f3f3f;
const int MOD=5000,STA=100010;
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

struct Hash
{
    int i,size,next[STA];
    int f[MOD],sg[STA];
    LL sta[STA];
    void init(){
        size=0;
        mem(f,-1);
    }
    int find(LL a){
        int s=a%MOD;
        for(i=f[s];i!=-1;i=next[i]){
            if(sta[i]==a){
                return sg[i];
            }
        }
        sta[size]=a;sg[size]=0;
        next[size]=f[s];
        f[s]=size++;
        return -1;
    }
    void update(LL a){
        int s=a%MOD;
        for(i=f[s];i!=-1 && sta[i]!=a;i=next[i]);
        sg[i]=1;
    }
}hs;

LL n;

int dfs(LL u)
{
    if(u>=n)return 0;
    int i,t,sg,ret=0;
    if((t=hs.find(u))!=-1)return t;
    for(i=2;i<=9;i++){
        sg=dfs(u*i);
        if(!sg)ret=1,hs.update(u);
    }
    return ret;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%I64d",&n))
    {
        hs.init();
        printf("%s wins.\n",dfs((LL)1)?"Stan":"Ollie");
    }
    return 0;
}