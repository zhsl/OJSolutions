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
#define pdi pair<double,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=1010,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Node{
    int x,y,z;
}a[N];
double w[N][N],d[N];
int vis[N];
int n;

inline double dist(Node &a,Node &b)
{
    return sqrt((double)((a.x-b.x)*(a.x-b.x)+
                (a.y-b.y)*(a.y-b.y)));
}
/*
double prim(int s,double mid)
{
    int i,u,v;
    double sum=0,t;
    priority_queue<pdi,vector<pdi>,greater<pdi> > q;
    for(i=0;i<n;i++)d[i]=DNF;d[s]=0;
    q.push(make_pair(0,s));
    mem(vis,0);
    while(!q.empty()){
        u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        sum+=d[u];
        for(v=0;v<n;v++){
            if(!vis[v] && (t=abs(a[u].z-a[v].z)-mid*w[u][v])<d[v]){
                d[v]=t;
                q.push(make_pair(t,v));
            }
        }
    }
    return sum;
}*/
double prim(int s,double mid)
{
    int i,u,v,x;
    double sum=0,t,m;
    mem(vis,0);
    for(i=0;i<n;i++)d[i]=DNF;d[s]=0;
    for(i=0;i<n;i++){
        m=DNF;
        for(x=0;x<n;x++)if(!vis[x] && d[x]<m)m=d[u=x];
        vis[u]=1;
        sum+=d[u];
        for(v=0;v<n;v++){
            if(!vis[v] && (t=abs(a[u].z-a[v].z)-mid*w[u][v])<d[v])
                d[v]=t;
        }
    }
    return sum;
}

double binary()
{
    double l=0,r=200000,mid;
    while(r-l>1e-4){
        mid=l+(r-l)/2;
        if(prim(1,mid)<0)r=mid;
        else l=mid;
    }
    return mid;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                w[i][j]=w[j][i]=dist(a[i],a[j]);

        printf("%.3lf\n",binary());
    }
    return 0;
}