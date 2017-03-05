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
typedef long long LL;
typedef unsigned long long ULL;
//const
const int N=510;
const int INF=0x3f3f3f3f;
const int MOD=1e10+7,STA=8000010;
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

int n,m;
char tu[N][N];
int vis[N][N];
int k;

struct Node{
    int x1,x2,y1,y2,k;
    int x,y;
}w[N*N];

int dfs(int x,int y)
{
    vis[x][y]=k;
    w[k].x1=Min(w[k].x1,x);
    w[k].x2=Max(w[k].x2,x);
    w[k].y1=Min(w[k].y1,y);
    w[k].y2=Max(w[k].y2,y);
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
        if(vis[nx][ny] || tu[nx][ny]=='0')continue;
        dfs(nx,ny);
    }
    return 1;
}

int cmp(const Node &a, const Node &b){
    //return a.y1!=b.y1?a.y1<b.y1:(a.x1!=b.x1?a.x1<b.x1:a.x2<b.x2);
    return a.y!=b.y?a.y<b.y:a.x<b.x;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++){
            scanf("%s",tu[i]);
        }

        mem(vis,0);
        k=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || tu[i][j]=='0')continue;
                w[k].x1=INF,w[k].x2=0,w[k].y1=INF,w[k].y2=0;
                w[k].x=w[k].y=INF;
                w[k].k=k;
                dfs(i,j);
                k++;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]) continue;
                if(j<w[vis[i][j]].y || (j==w[vis[i][j]].y && i<w[vis[i][j]].x)){
                    w[vis[i][j]].x=i,w[vis[i][j]].y=j;
                }
            }
        }

        sort(w+1,w+k,cmp);

        for(int p=1;p<k;p++){
            printf("%d %d\n",w[p].x2-w[p].x1+1, w[p].y2-w[p].y1+1);
            for(int i=w[p].x1;i<=w[p].x2;i++){
                for(int j=w[p].y1;j<=w[p].y2;j++){
                    printf("%c",(vis[i][j]==w[p].k && tu[i][j]=='1')?'1':'0');
                }
                printf("\n");
            }
        }
    }
    return 0;
}

