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
const int N=55,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

struct Node{
    double x,y;
}nod[N][12];

int n,cou[N];

double dist(Node &a)
{
    return a.x*a.x+a.y*a.y;
}

void getr(Node& r,Node& a,Node& b)
{
    r.x=a.x-b.x;
    r.y=a.y-b.y;
}

double cha(Node& r1,Node& r2)
{
    return r1.x*r2.y-r2.x*r1.y;
}

int judge(int k,int sta,int dir)
{
    int i,j;
    Node r0,rj,r01,rj1;
    for(i=1,j=sta+dir;i<cou[0];i++,j+=dir){
        getr(r0,nod[0][i],nod[0][i-1]);
        getr(rj,nod[k][j],nod[k][j-dir]);
        if(dist(r0)!=dist(rj))return 0;
        if(i<cou[0]-1){
            getr(r01,nod[0][i+1],nod[0][i]);
            getr(rj1,nod[k][j+dir],nod[k][j]);
            if(cha(r01,r0)!=cha(rj1,rj))return 0;
        }
    }
    return 1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d",&n) && n)
    {
        for(i=0;i<=n;i++){
            scanf("%d",&cou[i]);
            for(j=0;j<cou[i];j++)
                scanf("%lf%lf",&nod[i][j].x,&nod[i][j].y);
        }

        for(i=1;i<=n;i++){
            if(cou[i]!=cou[0])continue;
            if(judge(i,0,1) || judge(i,cou[i]-1,-1))
                printf("%d\n",i);
        }
        printf("+++++\n");
    }
    return 0;
}