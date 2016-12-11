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
const int N=300;
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

int ma[N],A[N][N],B[N],vis[N],num[N];

void getA(int n)
{
    int i,j,k;
    mem(A,0);
    for(i=0;i<n;i++){
        A[i][i]=1;A[i][n]=ma[i];
        if(i-1>=0)A[i][i-1]=1;
        if(i+1<n)A[i][i+1]=1;
    }
}

int gauss(int n)
{
    int i,j,k,cnt,row,ok,ret,up,free;
    for(i=row=0;i<n;i++){
        if(!A[row][i]){
            for(j=row+1;j<n;j++){
                if(A[j][i]){
                    for(k=i;k<=n;k++)swap(A[row][k],A[j][k]);
                    break;
                }
            }
        }
        if(A[row][i]!=1)continue;
        for(j=0;j<n;j++){
            if(j!=row && A[j][i]){
                for(k=i;k<=n;k++)
                    A[j][k]^=A[row][k];
            }
        }
        row++;
    }
    for(i=n-1;i>=row;i--)
        if(A[i][n])return -1;
    if(row==n){
        for(i=ret=0;i<n;i++)if(A[i][n])ret++;
        return ret;
    }
    mem(vis,0);
    for(i=k=j=0;i<n;i++,j++){
        while(!A[i][j] && j<n){
            vis[j]=1;
            num[k++]=j++;
        }
    }
    ret=INF;free=n-row;
    up=1<<free;
    for(k=0;k<up;k++){
        for(i=0;i<free;i++)B[num[i]]=(k&(1<<i))?1:0;
        for(i=n-1;i>=0;i--){
            if(vis[i])continue;
            B[i]=0;
            for(j=row;j<n;j++)B[i]^=B[j]*A[i][j];
            B[i]^=A[i][n];
        }
        for(i=cnt=0;i<n;i++)if(B[i])cnt++;
        ret=Min(ret,cnt);
    }
    return ret;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    while(~scanf("%d",&ma[0]))
    {
        for(i=1;i<20;i++)
            scanf("%d",&ma[i]);

        getA(20);

        ans=gauss(20);
        if(ans>=0)printf("%d\n",ans);
    }
    return 0;
}