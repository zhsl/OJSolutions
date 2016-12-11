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
const int N=210;
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
    double y,x1,x2;
    int c;
    Seg(){}
    Seg(double a,double b,double c,int d):y(a),x1(b),x2(c),c(d){}
    bool operator < (const Seg& a)const{
        return y<a.y;
    }
}seg[N];
double hs[N];
int len[N<<2],cnt[N<<2];
int n,m;

void pushup(int l,int r,int rt)
{
    if(cnt[rt])len[rt]=hs[r+1]-hs[l];
    else if(l==r)len[rt]=0;
    else len[rt]=len[rt<<1]+len[rt<<1|1];
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

int binary(int l,int r,int tar)
{
    int mid;
    while(l<r){
        mid=(l+r)>>1;
        if(hs[mid]==tar)return mid;
        else if(hs[mid]>tar)r=mid;
        else l=mid+1;
    }
    return mid;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,ca=1;
    double ans,a,b,c,d;
    while(~scanf("%d",&n) && n)
    {
        m=1;
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            hs[m]=a;
            seg[m++]=Seg(b,a,c,1);
            hs[m]=c;
            seg[m++]=Seg(d,a,c,-1);
        }
        sort(hs+1,hs+m);
        sort(seg,seg+m);
        for(i=1,k=0;i<m;i++)
            if(hs[i]!=hs[k])hs[++k]=hs[i];
        mem(len,0);mem(cnt,0);
        ans=0;
        for(i=0;i<m-1;i++){
            a=binary(0,k+1,seg[i].x1);
            b=binary(0,k+1,seg[i].x2)-1;
            if(a<b)update(a,b,seg[i].c,0,k,1);
            ans+=len[1]*(seg[i+1].y-seg[i].y);
        }

        printf("Test case #%d\nTotal explored area: %.2lf\n\n",ca++,ans);
    }
    return 0;
}