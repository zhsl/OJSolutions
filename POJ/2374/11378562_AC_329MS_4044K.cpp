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
#include<map>
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=50010,M=100000,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

int l[N][2],f[N][2],sta[200010<<2];
int n,s,w,a,b;

void update(int l,int r,int rt)
{
    if(a<=l && r<=b){
        sta[rt]=w;
        return;
    }
    if(sta[rt]>=0){
        sta[rt<<1]=sta[rt<<1|1]=sta[rt];
        sta[rt]=-1;
    }
    int mid=(l+r)>>1;
    if(a<=mid)update(lson);
    if(b>mid)update(rson);
}

void query(int l,int r,int rt)
{
    if(sta[rt]!=-1){
        w=sta[rt];
        return;
    }
    int mid=(l+r)>>1;
    if(a<=mid)query(lson);
    else query(rson);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    while(~scanf("%d%d",&n,&s))
    {
        mem(f,INF);
        mem(sta,0);
        for(i=1;i<=n;i++){
            scanf("%d%d",&l[i][0],&l[i][1]);
            l[i][0]+=M;l[i][1]+=M;
        }
        f[0][0]=f[0][1]=0;
        l[0][0]=l[0][1]=M;
        for(i=1;i<=n;i++){
            w=0;a=l[i][0];
            query(0,M<<1,1);
            f[i][0]=Min(f[w][0]+abs(l[i][0]-l[w][0]),f[w][1]+abs(l[i][0]-l[w][1]));
            w=0;a=l[i][1];
            query(0,M<<1,1);
            f[i][1]=Min(f[w][0]+abs(l[i][1]-l[w][0]),f[w][1]+abs(l[i][1]-l[w][1]));
            a=l[i][0],b=l[i][1];w=i;
            update(0,M<<1,1);
        }

        ans=Min(f[n][0]+abs(s+M-l[n][0]),f[n][1]+abs(s+M-l[n][1]));
        printf("%d\n",ans);
    }
    return 0;
}