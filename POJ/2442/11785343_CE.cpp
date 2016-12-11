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
const int N=2010;
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

int a[N],b[N],temp[N];
int T,m,n;

struct Node{
    int num,a,b;
    friend bool operator < (const Node &a,const Node &b){\
        return a.num>b.num;
    }
};

priority_queue<Node> q;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    Node t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=1;i<m;i++){
            while(!q.empty())q.pop();
            for(j=0;j<n;j++)
                scanf("%d",&b[j]);
            sort(b,b+n);
            for(j=0;j<n;j++)
                q.push(Node{a[j]+b[0],j,0});
            for(j=0;j<n;j++){
                t=q.top();q.pop();
                temp[j]=t.num;
                q.push(Node{a[t.a]+b[t.b+1],t.a,t.b+1});
            }
            for(j=0;j<n;j++)a[j]=temp[j];
        }

        printf("%d",a[0]);
        for(j=1;j<n;j++)
            printf(" %d",a[j]);
        putchar('\n');
    }
    return 0;
}