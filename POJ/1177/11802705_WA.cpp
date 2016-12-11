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
const int N=10010;
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

struct Seg{
    int y,x1,x2;
    int c;
    Seg(){}
    Seg(int a,int b,int c,int d):y(a),x1(b),x2(c),c(d){}
    bool operator < (const Seg& a)const{
        return y<a.y;
    }
}seg[N];
bool lnod[N<<2],rnod[N<<2];
int len[N<<2],cnt[N<<2],cnt2[N<<2];
int n,m;

void pushup(int l,int r,int rt)
{
    if(cnt[rt]){
        lnod[rt]=rnod[rt]=true;
        len[rt]=r-l+1;
        cnt2[rt]=2;
    }
    else if(l==r)cnt2[rt]=lnod[rt]=rnod[rt]=len[rt]=0;
    else {
        int ls=rt<<1,rs=rt<<1|1;
        lnod[rt]=lnod[ls],rnod[rt]=rnod[rs];
        len[rt]=len[ls]+len[rs];
        cnt2[rt]=cnt2[ls]+cnt2[rs];
        if(rnod[ls] && lnod[rs])cnt2[rt]-=2;
    }
}

void update(int a,int b,int c,int l,int r,int rt)
{
    if(a<=l && r<=b){
        cnt[rt]+=c;
        pushup(l,r,rt);
        return;
    }
    int mid=(l+r)>>1;
    if(a<=mid)update(a,b,c,lson);
    if(b>mid)update(a,b,c,rson);
    pushup(l,r,rt);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,l,r,a,b,c,d,ans,last;
    const int M=10000;
    while(~scanf("%d",&n))
    {
        m=0;
        for(i=0;i<n;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a+=M,b+=M,c+=M,d+=M;
            seg[m++]=Seg(b,a,c,1);
            seg[m++]=Seg(d,a,c,-1);
        }
        sort(seg,seg+m);
        mem(len,0);mem(cnt,0),mem(cnt2,0);
        mem(lnod,0);mem(rnod,0);
        ans=last=0;
        for(i=0;i<m-1;i++){
            update(seg[i].x1,seg[i].x2-1,seg[i].c,0,20000,1);
            ans+=cnt2[1]*(seg[i+1].y-seg[i].y);
            ans+=abs(len[1]-last);
            last=len[1];
        }
        update(seg[i].x1,seg[i].x2-1,seg[i].c,0,20000,1);

        printf("%d\n",ans+abs(len[1]-last));
    }
    return 0;
}