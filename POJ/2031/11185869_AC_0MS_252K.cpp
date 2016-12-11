#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=110,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Node{
    double x,y,z,r;
}nod[N];
double w[N][N],d[N];
int vis[N];
int n;

inline double dist(Node &a,Node &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)
                +(a.z-b.z)*(a.z-b.z));
}

double mintree()
{
    int i,j,x;
    double m,ans=0;
    for(i=0;i<n;i++)d[i]=DNF;
    d[0]=0;
    mem(vis,0);
    for(i=0;i<n;i++){
        m=DNF;
        for(j=0;j<n;j++)if(d[j]<m && !vis[j])m=d[x=j];
        vis[x]=1;
        ans+=d[x];
        for(j=0;j<n;j++){
            if(w[x][j]<d[j] && !vis[j])
                d[j]=w[x][j];
        }
    }
    return ans;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    double t;
    while(~scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)w[i][j]=DNF;
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&nod[i].x,&nod[i].y,&nod[i].z,&nod[i].r);
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                t=dist(nod[i],nod[j])-nod[i].r-nod[j].r;
                w[i][j]=w[j][i]=t>0?t:0;
            }
        }

        printf("%.3lf\n",mintree());
    }
    return 0;
}