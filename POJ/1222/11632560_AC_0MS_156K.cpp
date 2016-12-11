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
const int N=35;
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

int ma[N][N],A[N][N],B[N];
int T;

void getA(int n,int m)
{
    int i,j,k,x,y;
    mem(A,0);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            A[i*6+j][i*6+j]=1;
            for(k=0;k<4;k++){
                x=i+dx[k];
                y=j+dy[k];
                if(x>=0&&x<n && y>=0&&y<m){
                    A[i*6+j][x*6+y]=1;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            A[i*6+j][30]=ma[i][j];
    }
}

void gauss(int n)
{
    int i,j,k;
    for(i=0;i<n;i++){
        if(!A[i][i]){
            for(j=i+1;j<n;j++){
                if(A[j][i]){
                    for(k=i;k<=n;k++)swap(A[i][k],A[j][k]);
                    break;
                }
            }
        }
        for(j=i+1;j<n;j++){
            if(A[j][i]){
                for(k=i;k<=n;k++)
                    A[j][k]^=A[i][k];
            }
        }
    }
    for(i=n-1;i>=0;i--){
        k=0;
        for(j=i+1;j<n;j++)k^=A[i][j]*B[j];
        B[i]=k^A[i][n];
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ca=1;
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<5;i++){
            for(j=0;j<6;j++)
                scanf("%d",&ma[i][j]);
        }
        getA(5,6);

        gauss(30);

        printf("PUZZLE #%d\n",ca++);
        for(i=0;i<5;i++){
            printf("%d",B[i*6]);
            for(j=1;j<6;j++)
                printf(" %d",B[i*6+j]);
            putchar('\n');
        }
    }
    return 0;
}