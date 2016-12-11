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
const int N=14010,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int sta[N],q[N][90],cou[N];
LL f[12][N];
int n,m,stacou;

void dfs(int cur,int a,int one)
{
    if(cur==m){
        if(one)f[0][stacou]=1;
        sta[stacou++]=a;
        return;
    }
    dfs( cur+1,a,one&one);
    dfs( cur+1,a|(1<<(cur<<1)),0 );
    if(cur+2<=m)dfs( cur+2,a|(15<<(cur<<1)),one&one );
    return;
}

void match()
{
    int i,j,p,ok;
    for(i=0;i<stacou;i++){
        for(j=0;j<stacou;j++){
            for(p=0,ok=1;p<m;p++){
                if( (sta[i]&(1<<(p<<1)))==0 && (sta[j]&(1<<(p<<1)))!=0 )continue;
                else if( (sta[i]&(3<<(p<<1)))==(1<<(p<<1))
                   && (sta[j]&(1<<(p<<1)))==0 )continue;
                else if( (sta[i]&(3<<(p<<1)))==(3<<(p<<1))
                    && sta[j]&(3<<(p<<1)) )continue;
                else {ok=0;break;}
            }
            if(ok)q[i][cou[i]++]=j;
        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int k,i,j,ok;
    LL ans;
    while(~scanf("%d%d",&n,&m) && (n||m))
    {
        if((n*m)&1){printf("0\n");continue;}
        if(m>n)n^=m^=n^=m;
        ans=0;
        mem(f,0);
        mem(cou,0);
        stacou=0;
        dfs(0,0,1);
        match();
        for(k=1;k<n;k++){
            for(i=0;i<stacou;i++){
                for(j=0;j<cou[i];j++)
                    f[k][i]+=f[k-1][q[i][j]];
            }
        }
        k--;
        for(i=0;i<stacou;i++){
            for(j=0,ok=1;j<m;j++){
                if( (sta[i]&(1<<(j<<1)))==0){ok=0;break;};
            }
            if(ok)ans+=f[k][i];
        }

        printf("%I64d\n",ans);
    }
    return 0;
}