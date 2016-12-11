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
const int N=30,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Node{
    double x,y;
}nod[N];
struct Line{
    double x1,y1,x2,y2;
}lin[N];
int n;

void linef(Line &a,double &A,double &B,double &C)
{
    A=-(a.y1-a.y2);
	B=a.x1-a.x2;
	C=-A*a.x1-B*a.y1;
}

int las(Line &a,Line &b)   //跨立实验
{
	Node r1,r0,r2;
	r1.x=a.x1-b.x1;
	r1.y=a.y1-b.y1;
	r0.x=b.x2-b.x1;
	r0.y=b.y2-b.y1;
	r2.x=a.x2-b.x1;
	r2.y=a.y2-b.y1;
	if( ((r1.x*r0.y)-(r0.x*r1.y))
		*((r2.x*r0.y)-(r0.x*r2.y))<=0 )return 1;
	else return 0;
}

double getx(Line &a,Line &b)
{
    double a1,b1,c1,a2,b2,c2;
    linef(a,a1,b1,c1);
    linef(b,a2,b2,c2);
    return (c2*b1-c1*b2)/(a1*b2-a2*b1);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,ok;
    double  ans;
    Line t,lz;
    while(~scanf("%d",&n) && n)
    {
        ok=0;
        ans=-DNF;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&nod[i].x,&nod[i].y);
            lin[i].x1=lin[i].x2=nod[i].x;
            lin[i].y1=nod[i].y-1;lin[i].y2=nod[i].y;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j)continue;
                lz.x1=nod[i].x,lz.y1=nod[i].y;
                lz.x2=nod[j].x,lz.y2=nod[j].y-1;
                for(k=0;k<n;k++){
                    if(las(lin[k],lz))continue;
                    else {
                        if(k>0){
                            t.x1=nod[k-1].x,t.y1=nod[k-1].y;
                            t.x2=nod[k].x,t.y2=nod[k].y;
                            ans=Max(ans,getx(lz,t));
                            t.y1--,t.y2--;
                            ans=Max(ans,getx(lz,t));
                        }
                        break;
                    }
                }
                if(k==n){ok=1;break;}
            }
        }

        if(ok)printf("Through all the pipe.\n");
        else printf("%.2lf\n",ans);
    }
    return 0;
}