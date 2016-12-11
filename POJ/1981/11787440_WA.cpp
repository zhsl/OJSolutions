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
}nod[N],O;
int n;

double dist(Node &a,Node &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void getO(Node &a,Node &b,int dir)
{
    double t=dist(a,b)/2.0;
    t=dir*sqrt((1.0-t*t));
    if(a.y==b.y){
        O.x=(a.x+b.x)/2.0;
        O.y=a.y+t;
    }
    else if(a.x==b.x){
        O.y=(a.y+b.y)/2.0;
        O.x=a.x+t;
    }
    else {
        double kt;
        kt=atan(-(a.x-b.x)/(a.y-b.y));
        O.x=(a.x+b.x)/2.0+cos(kt)*t;
        O.y=(a.y+b.y)/2.0+sin(kt)*t;
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,ans,tot;
    while(scanf("%d",&n) && n)
    {
        ans=0;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&nod[i].x,&nod[i].y);
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(dist(nod[i],nod[j])<2.0){
                    getO(nod[i],nod[j],-1);
                    for(tot=2,k=0;k<n;k++){
                        if(k==i || k==j)continue;
                        if(dist(O,nod[k])-1.0<EPS)tot++;
                    }
                    if(tot>ans)ans=tot;
                    getO(nod[i],nod[j],1);
                    for(tot=2,k=0;k<n;k++){
                        if(k==i || k==j)continue;
                        if(dist(O,nod[k])-1.0<EPS)tot++;
                    }
                    if(tot>ans)ans=tot;
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}