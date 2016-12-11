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
const int N=500010;
const int INF=0x3f3f3f3f;
const int MOD=10007,STA=8000010;
const LL LNF=1LL<<55;
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
    LL x,y;
    LL id,index;
    Node(){}
    Node(LL _x,LL _y,LL _index):x(_x),y(_y),index(_index){}
}p[N],nod[N],temp[N];

int n;

LL dist(Node &a,Node &b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int cmpxy(Node a,Node b)
{
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}

int cmpy(Node a,Node b)
{
    return a.y<b.y;
}

pii Closest_Pair(int l,int r)
{
    if(l==r || l+1==r)return pii(l,r);
    LL d,d1,d2;
    int i,j,k,mid=(l+r)/2;
    pii pn1=Closest_Pair(l,mid);
    pii pn2=Closest_Pair(mid+1,r);
    d1=(pn1.first==pn1.second?LNF:dist(nod[pn1.first],nod[pn1.second]));
    d2=(pn2.first==pn2.second?LNF:dist(nod[pn2.first],nod[pn2.second]));
    pii ret;
    d=Min(d1,d2);
    ret=d1<d2?pn1:pn2;
    for(i=l,k=0;i<=r;i++){
        if((nod[mid].x-nod[i].x)*(nod[mid].x-nod[i].x)<=d){
            temp[k++]=nod[i];
        }
    }
    sort(temp,temp+k,cmpy);
    for(i=0;i<k;i++){
        for(j=i+1;j<k && (temp[j].y-temp[i].y)*(temp[j].y-temp[i].y)<d;j++){
            if(dist(temp[i],temp[j])<d){
                d=dist(temp[i],temp[j]);
                ret=make_pair(temp[i].id,temp[j].id);
            }
        }
    }

    return ret;
}

void Init()
{
    int i;
    LL x,y,Ax,Bx,Cx,Ay,By,Cy;
    cin>>n>>Ax>>Bx>>Cx>>Ay>>By>>Cy;
    x=y=0;
    for(i=0;i<n;i++){
        x=(x*Ax+Bx)%Cx;
        y=(y*Ay+By)%Cy;
        p[i]=Node(x,y,i);
    }
}

int main(){
 //   freopen("in.txt","r",stdin);
    int n,i,j;
    int ans,s,t1,t2;
    while(~scanf("%d",&n) && n!=-1)
    {
        t1=ans=0;
        while(n--){
            scanf("%d%d",&s,&t2);
            ans+=s*(t2-t1);
            t1=t2;
        }

        printf("%d miles\n",ans);
    }
    return 0;
}