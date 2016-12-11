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
const int N=200010;
const int INF=0x3f3f3f3f;
const int MOD=10007,STA=8000010;
const LL LNF=1LL<<55;
const double EPS=1e-8;
const double OO=1e30;
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
    int id,index;
    Node(){}
    Node(double _x,double _y,int _index):x(_x),y(_y),index(_index){}
}nod[N],temp[N];

int n;

double dist(Node &a,Node &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmpxy(Node a,Node b)
{
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}

bool cmpy(Node a,Node b)
{
    return a.y<b.y;
}

pii Closest_Pair(int l,int r)
{
    if(l==r || l+1==r)return pii(l,r);
    double d,d1,d2;
    int i,j,k,mid=(l+r)/2;
    pii pn1=Closest_Pair(l,mid);
    pii pn2=Closest_Pair(mid+1,r);
    if(pn1.first==pn1.second || nod[pn1.first].index==nod[pn1.second].index)
        d1=OO;
    else d1=dist(nod[pn1.first],nod[pn1.second]);
    if(pn2.first==pn2.second || nod[pn2.first].index==nod[pn2.second].index)
        d2=OO;
    else d2=dist(nod[pn2.first],nod[pn2.second]);

    pii ret;
    d=Min(d1,d2);
    ret=d1<d2?pn1:pn2;

    for(i=l,k=0;i<=r;i++){
        if(fabs(nod[mid].x-nod[i].x)<=d){
            temp[k++]=nod[i];
        }
    }
    sort(temp,temp+k,cmpy);
    for(i=0;i<k;i++){
        for(j=i+1;j<k && fabs(temp[j].y-temp[i].y)<d;j++){
            if(dist(temp[i],temp[j])<d && (temp[i].index^temp[j].index)){
                d=dist(temp[i],temp[j]);
                ret=make_pair(temp[i].id,temp[j].id);
            }
        }
    }
    return ret;
}

void Init()
{
    int i,t;
    double x,y;
    scanf("%d",&t);
    n=t<<1;
    for(i=0;i<t;i++){
        scanf("%lf%lf",&x,&y);
        nod[i]=Node(x,y,0);
    }
    for(;i<n;i++){
        scanf("%lf%lf",&x,&y);
        nod[i]=Node(x,y,1);
    }
    sort(nod,nod+n,cmpxy);
    for(i=0;i<n;i++)nod[i].id=i;
}

int main(){
 //   freopen("in.txt","r",stdin);
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        pii ans=Closest_Pair(0,n-1);

        printf("%.3lf\n",dist(nod[ans.first],nod[ans.second]));
    }
    return 0;
}