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
const int N=50010;
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

int lsum[N<<2],msum[N<<2],rsum[N<<2],c[N<<2];
int n,m,a,b,val;

void pushdown(int rt,int dl,int dr)
{
    if(c[rt]==-1)return;
    c[rt<<1]=c[rt<<1|1]=c[rt];
    lsum[rt<<1]=msum[rt<<1]=rsum[rt<<1]=c[rt]?0:dl;
    lsum[rt<<1|1]=msum[rt<<1|1]=rsum[rt<<1|1]=c[rt]?0:dr;
}

void pushup(int rt,int dl,int dr)
{
    c[rt]=c[rt<<1]==c[rt<<1|1]?c[rt<<1]:-1;
    msum[rt]=Max(msum[rt<<1],msum[rt<<1|1],rsum[rt<<1]+lsum[rt<<1|1]);
    lsum[rt]=lsum[rt<<1]==dl?lsum[rt<<1]+lsum[rt<<1|1]:lsum[rt<<1];
    rsum[rt]=rsum[rt<<1|1]==dr?rsum[rt<<1|1]+rsum[rt<<1]:rsum[rt<<1|1];
}

void build(int l,int r,int rt)
{
    lsum[rt]=msum[rt]=rsum[rt]=r-l+1;
    c[rt]=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
}

void update(int l,int r,int rt)
{
  //  printf("%d %d %d\n",a,b,val);
    if(a<=l && r<=b){
        c[rt]=val;
        lsum[rt]=msum[rt]=rsum[rt]=val?0:r-l+1;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(rt,mid-l+1,r-mid);
    if(a<=mid)update(lson);
    if(b>mid)update(rson);
    pushup(rt,mid-l+1,r-mid);
}

int query(int l,int r,int rt)
{
 //   printf(" %d %d %d\n",l,r,a);
    if(l==r)return l;
    int mid=(l+r)>>1;
    pushdown(rt,mid-l+1,r-mid);
    if(msum[rt<<1]>=a)return query(lson);
    else if(rsum[rt<<1]+lsum[rt<<1|1]>=a)return mid-rsum[rt<<1]+1;
    else return query(rson);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,op,s;
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--){
            scanf("%d",&op);
            if(op==1){
                scanf("%d",&a);
                if(msum[1]<a)printf("0\n");
                else {
                    s=query(1,n,1);
                    printf("%d\n",s);
                    b=s+a-1;a=s;
                    val=1;
                    update(1,n,1);
                }
            }
            else {
                scanf("%d%d",&a,&b);
                b+=a-1;val=0;
                update(1,n,1);
            }
        }
    }
    return 0;
}