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
const int N=1010;
const int INF=0x3f3f3f3f;
const int MOD=256,STA=8000010;
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
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

struct Node{
    int x,y,z;
}r1[3],r2[3];
int T,n;

void re(Node &a,Node b)
{
    a.x=-b.x;
    a.y=-b.y;
    a.z=-b.z;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,d,x,y,z;
    char s[20];
    Node *p,*q;
    scanf("%d",&T);
    while(T--)
    {
        x=y=z=0;
        r1[0].x=1,r1[0].y=0,r1[0].z=0;
        r1[1].x=0,r1[1].y=1,r1[1].z=0;
        r1[2].x=0,r1[2].y=0,r1[2].z=1;
        scanf("%d",&n);
        while(n--){
            scanf("%s%d",s,&d);
            if(s[0]=='f'){
                r2[0]=r1[0],r2[1]=r1[1],r2[2]=r1[2];
            }
            else if(s[0]=='b'){
                re(r2[0],r1[0]);
                re(r2[1],r1[1]);
                r2[2]=r1[2];
            }
            else if(s[0]=='l'){
                re(r2[0],r1[1]);
                r2[1]=r1[0];
                r2[2]=r1[2];
            }
            else if(s[0]=='r'){
                r2[0]=r1[1];
                re(r2[1],r1[0]);
                r2[2]=r1[2];
            }
            else if(s[0]=='u'){
                r2[0]=r1[2];
                r2[1]=r1[1];
                re(r2[2],r1[0]);
            }
            else {
                re(r2[0],r1[2]);
                r2[1]=r1[1];
                r2[2]=r1[0];
            }

            x+=r2[0].x*d;
            y+=r2[0].y*d;
            z+=r2[0].z*d;
            swap(r2[0],r1[0]);
            swap(r2[1],r1[1]);
            swap(r2[2],r1[2]);
        }

        int ans;
        if(r1[0].x==1)ans=0;
        else if(r1[0].y==1)ans=1;
        else if(r1[0].z==1)ans=2;
        else if(r1[0].x==-1)ans=3;
        else if(r1[0].y==-1)ans=4;
        else ans=5;

        printf("%d %d %d %d\n",x,y,z,ans);
    }
    return 0;
}