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
//

struct Point{
    int x,y,id;
    bool operator<(const Point p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}p[N];
struct BIT{
    int min_val,pos;
    void init(){
        min_val=INF;
        pos=-1;
    }
}bit[N];
struct Edge{
    int u,v,d;
    bool operator<(const Edge e)const{
        return d<e.d;
    }
}e[N<<2];
int T[N],hs[N];
int n,mt,pre[N];

void adde(int u,int v,int d)
{
    e[mt].u=u,e[mt].v=v;
    e[mt++].d=d;
}

int find(int x)
{
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int dist(int i,int j)
{
    return abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
}

inline int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int val,int pos)
{
    for(int i=x;i>=1;i-=lowbit(i))
        if(val<bit[i].min_val)
            bit[i].min_val=val,bit[i].pos=pos;
}

int query(int x,int m)
{
    int min_val=INF,pos=-1;
    for(int i=x;i<=m;i+=lowbit(i))
        if(bit[i].min_val<min_val)
            min_val=bit[i].min_val,pos=bit[i].pos;
    return pos;
}

int Manhattan_minimum_spanning_tree(int n,Point *p,int K)
{
    int i,w,dir,fa,fb,pos,u,v,m;
    //Build graph
    mt=0;
    for(dir=0;dir<4;dir++){
        //Coordinate transform - reflect by y=x and reflect by x=0
        if(dir==1||dir==3){
            for(i=0;i<n;i++)
                swap(p[i].x,p[i].y);
        }
        else if(dir==2){
            for(i=0;i<n;i++){
                p[i].x=-p[i].x;
            }
        }
        //Sort points according to x-coordinate
        sort(p,p+n);
        //Discretize
        for(i=0;i<n;i++){
            T[i]=hs[i]=p[i].y-p[i].x;
        }
        sort(hs,hs+n);
        m=unique(hs,hs+n)-hs;
        //Initialize BIT
        for(i=1;i<=m;i++)
            bit[i].init();
        //Find points and add edges
        for(i=n-1;i>=0;i--){
            pos=lower_bound(hs,hs+m,T[i])-hs+1;   //BIT中从1开始'
            w=query(pos,m);
            if(w!=-1)
                adde(p[i].id,p[w].id,dist(i,w));
            update(pos,p[i].x+p[i].y,i);
        }
    }
    //Kruskal
    sort(e,e+mt);
    for(i=0;i<n;i++)pre[i]=i;
    for(i=0;i<mt;i++){
        u=e[i].u,v=e[i].v;
        fa=find(u),fb=find(v);
        if(fa!=fb){
            K--;pre[fa]=fb;
            if(K==0)return e[i].d;
        }
    }
}

int main(){
 //   freopen("in.txt","r",stdin);
    int i,j,k;
    while(~scanf("%d%d",&n,&k))
    {
        for(i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].id=i;
        }
        printf("%d\n",Manhattan_minimum_spanning_tree(n,p,n-k));
    }
    return 0;
}


