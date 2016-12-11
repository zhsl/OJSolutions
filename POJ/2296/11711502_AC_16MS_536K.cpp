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
const int N=110;
const int INF=0x3f3f3f3f;
const int MOD=5000,STA=100010;
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

int nod[N][2];
int first[N*2],next[N*N*4],vis[N*2],S[N*2];
int T,n,mt,cnt;

struct Edge{
    int u,v;
}e[N*N*4];

void adde(int a,int b)
{
    e[mt].u=a,e[mt].v=b;
    next[mt]=first[a];first[a]=mt++;
}

int dfs(int u)
{
    if(vis[u^1])return 0;
    if(vis[u])return 1;
    int i;
    vis[u]=1;
    S[cnt++]=u;
    for(i=first[u];i!=-1;i=next[i]){
        if(!dfs(e[i].v))return 0;
    }
    return 1;
}

int Twosat()
{
    int i,j;
    for(i=0;i<n;i+=2){
        if(vis[i] || vis[i^1])continue;
        cnt=0;
        if(!dfs(i)){
            while(cnt)vis[S[--cnt]]=0;
            if(!dfs(i^1))return 0;
        }
    }
    return 1;
}

int judge(double *a1,double *a2,double *b1,double *b2)
{
    if(Max(a1[0],a2[0])<=Min(b1[0],b2[0])
       || Min(a1[0],a2[0])>=Max(b1[0],b2[0])
       || Max(a1[1],a2[1])<=Min(b1[1],b2[1])
       || Min(a1[1],a2[1])>=Max(b1[1],b2[1]))return 0;
    return 1;
}

void init(double limt)
{
    int i,j,x,y;
    double a1[2],a2[2],b1[2],b2[2];
    mt=0;mem(vis,0);
    mem(first,-1);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            x=i<<1;y=j<<1;
            a1[0]=nod[i][0]-limt/2,a1[1]=nod[i][1];b1[0]=nod[j][0]-limt/2,b1[1]=nod[j][1];
            a2[0]=nod[i][0]+limt/2,b2[0]=nod[j][0]+limt/2;
            a2[1]=nod[i][1]-limt;b2[1]=nod[j][1]-limt;
            if(judge(a1,a2,b1,b2)){
                adde(x,y^1);adde(y,x^1);
            }
            b2[1]=nod[j][1]+limt;
            if(judge(a1,a2,b1,b2)){
                adde(x,y);adde(y^1,x^1);
            }
            a2[1]=nod[i][1]+limt;b2[1]=nod[j][1]-limt;
            if(judge(a1,a2,b1,b2)){
                adde(x^1,y^1);adde(y,x);
            }
            b2[1]=nod[j][1]+limt;
            if(judge(a1,a2,b1,b2)){
                adde(x^1,y);adde(y^1,x);
            }
        }
    }
}

int binary(int l,int r)
{
    int mid;
    while(l<r){
        mid=(l+r)>>1;
        init(mid);
        if(Twosat())l=mid+1;
        else r=mid;
    }
    return l;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&nod[i][0],&nod[i][1]);
        }

        printf("%d\n",binary(0,20001)-1);
    }
    return 0;
}