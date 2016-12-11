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
const int N=210,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000;

struct Node{
    double x,y;
}nod[N],peg;
int n;
double pr;

double disln(Node &l1,Node &l2,Node &o){
	double A,B,C;
	A=-(l1.y-l2.y);
	B=l1.x-l2.x;
	C=-A*l1.x-B*l1.y;
	return fabs(A*o.x+B*o.y+C)/sqrt(A*A+B*B);
}

inline void getr(Node &r,Node *a)
{
    r.x=a[1].x-a[0].x;
    r.y=a[1].y-a[0].y;
}

int ispro(Node *a)
{
    int i,ok;
    double ini;
    Node r1,r2;
    getr(r1,a);getr(r2,a+1);
    ini=r1.x*r2.y-r2.x*r1.y;
    for(i=2;i<=n;i++){
        r1=r2;
        getr(r2,a+i);
        if((r1.x*r2.y-r2.x*r1.y)*ini<0)return 0;
    }

    return 1;
}

int isconcir(Node *a)
{
    int i,j;
    Node r1,r2;
    double ini;
    for(i=0;i<n;i++)
        if(disln(a[i],a[i+1],peg)<pr)return 0;
    getr(r1,a);
    r2.x=peg.x-a[0].x;r2.y=peg.y-a[0].y;
    ini=r1.x*r2.y-r2.x*r1.y;
    for(i=1;i<n;i++){
        getr(r1,a+i);
        r2.x=peg.x-a[i].x;r2.y=peg.y-a[i].y;
        if((r1.x*r2.y-r2.x*r1.y)*ini<0)return 0;
    }
    return 1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d",&n) && n>2)
    {
        scanf("%lf%lf%lf",&pr,&peg.x,&peg.y);
        for(i=0;i<n;i++){
            scanf("%lf%lf",&nod[i].x,&nod[i].y);
        }
        nod[n].x=nod[0].x;nod[n].y=nod[0].y;
        nod[n+1].x=nod[1].x;nod[n+1].y=nod[1].y;

        if(!ispro(nod))printf("HOLE IS ILL-FORMED\n");
        else if(isconcir(nod))printf("PEG WILL FIT\n");
        else printf("PEG WILL NOT FIT\n");
    }
    return 0;
}