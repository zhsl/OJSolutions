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
const int N=310;
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

struct Node{
    double x,y;
}nod[N];
struct Point{
    double angle;
    int id;
    bool operator < (const Point& a)const{
        return angle<a.angle;
    }
}p[N*2];
int n;

double dist(Node &a,Node &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int slove()
{
    int i,j,ans,tot,k,cnt;
    ans=1;
    for(i=0;i<n;i++){
        for(j=k=0;j<n;j++){
            if(j==i || dist(nod[i],nod[j])>2.0)continue;
            double angle=atan2(nod[i].y-nod[j].y,nod[i].x-nod[j].x);
            double phi=acos(dist(nod[i],nod[j])/2);
            p[k].angle=angle-phi;p[k++].id=1;
            p[k].angle=angle+phi;p[k++].id=0;
        }
        sort(p,p+k);
        for(tot=1,j=0;j<k;j++){
            if(p[j].id)tot++;
            else tot--;
            ans=Max(ans,tot);
        }
    }
    return ans;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i;
    while(~scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&nod[i].x,&nod[i].y);

        printf("%d\n",slove());
    }
    return 0;
}