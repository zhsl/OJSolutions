#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>*/
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=1010,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

bool f[N<<2][N<<2];
int T,n,m,a,b,x1,y1,x2,y2,ans;

void updatey(int l,int r,int rt,int fa)
{
    if(y1<=l && r<=y2){
        f[fa][rt]^=1;
 //   printf(" %d %d %d\n",l,r,f[fa][rt]);//
        return;
    }
    int mid=(l+r)>>1;
    if(y1<=mid)updatey(lson,fa);
    if(y2>mid)updatey(rson,fa);
}

void updatex(int l,int r,int rt)
{
    if(x1<=l && r<=x2){
 //       printf("%d %d %d\n",l,r,f[rt][0]);//
        updatey(1,n,1,rt);
        return;
    }
    int mid=(l+r)>>1;
    if(x1<=mid)updatex(lson);
    if(x2>mid)updatex(rson);
}

void queryy(int l,int r,int rt,int fa)
{
    ans^=f[fa][rt];
 //   printf("  %d\n",f[fa][rt]);
    if(l==r)return;
    int mid=(l+r)>>1;
    if(y1<=mid)queryy(lson,fa);
    else queryy(rson,fa);
}

void queryx(int l,int r,int rt)
{
    queryy(1,n,1,rt);
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x1<=mid)queryx(lson);
    else queryx(rson);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    char c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        while(m--){
            getchar();
            scanf("%c",&c);
            if(c=='C'){
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                updatex(1,n,1);
            }
            else {
                scanf("%d%d",&x1,&y1);
                ans=0;
                queryx(1,n,1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}