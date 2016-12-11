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
const int N=40,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Node{
    double x,y;
}nod[N][N];
int n;

void linef(Node &l1,Node &l2,double &A,double &B,double &C){
	A=-(l1.y-l2.y);
	B=l1.x-l2.x;
	C=-A*l1.x-B*l1.y;
}

double getsum(Node &a,Node &b,Node &c, Node &d)
{
    double s;
    s=a.x*b.y-a.y*b.x;
    s+=b.x*c.y-b.y*c.x;
    s+=c.x*d.y-c.y*d.x;
    s+=d.x*a.y-d.y*a.x;
    return fabs(s*0.5);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    double a1,b1,c1,a2,b2,c2,ans;
    while(~scanf("%d",&n) && n)
    {
        ans=-DNF;
        nod[n+1][0].x=nod[n+1][0].y=0;
        nod[n+1][n+1].x=1,nod[n+1][n+1].y=0;
        for(i=1;i<=n;i++){
            scanf("%lf",&nod[n+1][i].x);
            nod[n+1][i].y=0;
        }
        nod[0][0].x=0,nod[0][0].y=1;
        nod[0][n+1].x=nod[0][n+1].y=1;
        for(i=1;i<=n;i++){
            scanf("%lf",&nod[0][i].x);
            nod[0][i].y=1;
        }
        for(i=n;i>=1;i--){
            scanf("%lf",&nod[i][0].y);
            nod[i][0].x=0;
        }
        for(i=n;i>=1;i--){
            scanf("%lf",&nod[i][n+1].y);
            nod[i][n+1].x=1;
        }

        for(i=1;i<=n;i++){
            linef(nod[i][0],nod[i][n+1],a1,b1,c1);
            for(j=1;j<=n;j++){
                linef(nod[0][j],nod[n+1][j],a2,b2,c2);
                nod[i][j].x=(c2*b1-c1*b2)/(a1*b2-a2*b1);
                nod[i][j].y=(a1*c2-a2*c1)/(a2*b1-a1*b2);
            }
        }
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                ans=Max(ans,getsum(nod[i][j],nod[i][j+1],nod[i+1][j+1],nod[i+1][j]));
        printf("%.6lf\n",ans);
    }
    return 0;
}