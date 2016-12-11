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
//Daily Use ...
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

int ma[N][N],ans[N],vis[N];
int T,n,m,k;

int topo()
{
    int i,j,all=n,cnt;
    while(all--){
        for(i=1;i<=n;i++){
            if(vis[i])continue;
            cnt=0;
            for(j=1;j<=n;j++){
                if(vis[j])continue;
                cnt+=ma[i][j];
            }
            if(!cnt)break;
        }
        if(cnt)return 0;
        ans[k++]=i;
        vis[i]=1;
        for(j=1;j<=n;j++){
            ma[j][i]=0;
        }
    }
    return 1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b;
    scanf("%d",&T);
    while(T--)
    {
        mem(ma,0);
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d",&a,&b);
            ma[b][a]=1;
        }

        k=0;mem(vis,0);
        if(topo()){
            printf("%d",ans[0]);
            for(i=1;i<k;i++)
                printf(" %d",ans[i]);
        }
        else printf("-1");
        putchar('\n');
    }
    return 0;
}