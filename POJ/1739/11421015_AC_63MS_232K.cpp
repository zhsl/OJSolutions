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
#define LL long long
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=15,INF=0x3f3f3f3f,MOD=4001,STA=1000010;
const double DNF=100000000000;

int g[N][N],code[N],ma[N];
int n,m,sx,sy,ex,ey;

struct Hash{
    int first[MOD],next[STA],size;
    LL f[STA],sta[STA];
    void init(){
        size=0;
        mem(first,-1);
    }
    void add(LL st,LL ans){
        int i,u=st%MOD;
        for(i=first[u];i!=-1;i=next[i]){
            if(sta[i]==st){
                f[i]+=ans;
                return;
            }
        }
        sta[size]=st;
        f[size]=ans;
        next[size]=first[u];
        first[u]=size++;
    }
}hs[2];

void shift(int p)
{
    int k;
    LL sta;
    for(k=0;k<hs[!p].size;k++){
        sta=hs[!p].sta[k]<<3;
        hs[p].add(sta,hs[!p].f[k]);
    }
}

LL getsta()
{
    LL i,cnt=1,sta=0;
    mem(ma,-1);
    ma[0]=0;
    for(i=0;i<=m;i++){
        if(ma[code[i]]==-1)ma[code[i]]=cnt++;
        code[i]=ma[code[i]];
        sta|=(LL)code[i]<<(3*i);
    }
    return sta;
}

void getcode(LL sta)
{
    int i;
    for(i=0;i<=m;i++){
        code[i]=sta&7;
        sta>>=3;
    }
}

void unblock(int i,int j,int p)
{
    int k,t;
    LL cnt,x,y;
    for(k=0;k<hs[!p].size;k++){
        getcode(hs[!p].sta[k]);
        x=code[j],y=code[j+1];
        cnt=hs[!p].f[k];
        if(x && y){
            if(x==y)continue;
            code[j]=code[j+1]=0;
            for(t=0;t<=m;t++)
                if(code[t]==y)code[t]=x;
            hs[p].add(getsta(),cnt);
        }
        else if((x&&!y) || (!x&&y)){
            if((i==sx && j==sy) || (i==ex && j==ey)){
                code[j]=code[j+1]=0;
                hs[p].add(getsta(),cnt);
            }
            else {
                t=x?x:y;
                if(g[i+1][j]){
                    code[j]=t;code[j+1]=0;
                    hs[p].add(getsta(),cnt);
                }
                if(g[i][j+1]){
                    code[j]=0;code[j+1]=t;
                    hs[p].add(getsta(),cnt);
                }
            }
        }
        else{
            if(i==sx && j==sy){
               if(g[i][j+1]){
                    code[j+1]=8;
                    hs[p].add(getsta(),cnt);
                }
            }
            else if(g[i+1][j] && g[i][j+1]){
                code[j]=code[j+1]=8;
                hs[p].add(getsta(),cnt);
            }
        }
    }
}

void block(LL j,int p)
{
    int k;
    for(k=0;k<hs[!p].size;k++){
        getcode(hs[!p].sta[k]);
        code[j]=code[j+1]=0;
        hs[p].add(getsta(),hs[!p].f[k]);
    }
}

LL slove()
{
    int i,j,p;
    hs[0].init();
    hs[p=1].init();
    hs[0].add(0,1);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(g[i][j])unblock(i,j,p);
            else block(j,p);
            hs[p=!p].init();
        }
        shift(p);
        hs[p=!p].init();
    }
    for(i=0;i<hs[!p].size;i++ )
        if(hs[!p].sta[i]==0)return hs[!p].f[i];
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    LL ans;
    char c;
    while(~scanf("%d%d",&n,&m) && (n || m))
    {
        mem(g,0);
        sx=n-1,sy=0;
        ex=n-1,ey=m-1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf(" %c",&c);
                g[i][j]=(c=='.');
            }
        }

        if(g[sx][sy]==0 || g[ex][ey]==0)ans=0;
        else if(n==m && n==1)ans=1;
        else ans=slove();

        printf("%I64d\n",ans);
    }
    return 0;
}