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
const int N=10,INF=0x3f3f3f3f,MOD=60007,STA=1000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=100000000000;

int g[N][N];
int n,m;

struct Hash{
    int first[MOD],next[STA],size;
    int f[STA],sta[STA];
    void init(){
        size=0;
        mem(first,-1);
    }
    void add(int st,int ans){
        int i,u=st%MOD;
        for(i=first[u];i!=-1;i=next[i]){
            if(sta[i]==st){
                f[i]=Min(f[i],ans);
                return;
            }
        }
        f[size]=ans;
        sta[size]=st;
        next[size]=first[u];
        first[u]=size++;
    }
}hs[2];

void shift(int p)
{
    int i,flag=(1<<((m+1)<<1))-1;
    for(i=0;i<hs[!p].size;i++){
        hs[p].add((hs[!p].sta[i]<<2)&flag,hs[!p].f[i]);
    }
}

int slove()
{
    int i,j,k,x,y,left,up,p,sta,f;
    hs[0].init();
    hs[0].add(0,0);
    hs[p=1].init();
    for(i=0;i<n;i++){
        for(j=0;j<m;j++,hs[p=!p].init()){
            for(k=0;k<hs[!p].size;k++){
                sta=hs[!p].sta[k];
                f=hs[!p].f[k]+1;
                x=(3<<(j<<1))&sta;
                y=(3<<((j+1)<<1))&sta;
                left=x>>(j<<1);
                up=y>>((j+1)<<1);
             //   printf(" %d %d %d\n",left,up,f-1);///
               /* for(int q=0;q<=m;q++){
                    printf("%d ",(sta&(3<<(q<<1)))>>(q<<1));
                }
                printf("  %d",f-1);
                putchar('\n');*/
                //
                if(g[i][j]){
                    if(g[i][j]==2){
                        if(left==2 && up==0){
                            hs[p].add(sta^x,f);
                        }
                        else if(left==0 && up==2){
                            hs[p].add(sta^y,f);
                        }
                        else if(left==0 && up==0){
                            if(g[i+1][j]==1 || g[i+1][j]==2)hs[p].add(sta|(2<<(j<<1)),f);
                            if(g[i][j+1]==1 || g[i][j+1]==2)hs[p].add(sta|(2<<((j+1)<<1)),f);
                        }
                    }
                    else if(g[i][j]==3){
                        if(left==3 && up==0){
                            hs[p].add(sta^x,f);
                        }
                        else if(left==0 && up==3){
                            hs[p].add(sta^y,f);
                        }
                        else if(left==0 && up==0){
                            if(g[i+1][j]==1 || g[i+1][j]==3)hs[p].add(sta|(3<<(j<<1)),f);
                            if(g[i][j+1]==1 || g[i][j+1]==3)hs[p].add(sta|(3<<((j+1)<<1)),f);
                        }
                    }
                    else {  //g[i][j]==1
                        if(left==up && left){
                            hs[p].add(sta^x^y,f);
                        }
                        else if((left==2 && up==0) || (left==0 && up==2)){
                            if(g[i+1][j])hs[p].add(sta^y|(2<<(j<<1)),f);
                            if(g[i][j+1])hs[p].add(sta^x|(2<<((j+1)<<1)),f);
                        }
                        else if((left==3 && up==0) || (left==0 && up==3)){
                            if(g[i+1][j])hs[p].add(sta^y|(3<<(j<<1)),f);
                            if(g[i][j+1])hs[p].add(sta^x|(3<<((j+1)<<1)),f);
                        }
                        else if(left==0 && up==0){
                            if(g[i+1][j] && g[i][j+1]){
                                hs[p].add(sta|(2<<(j<<1))|(2<<((j+1)<<1)),f);
                                hs[p].add(sta|(3<<(j<<1))|(3<<((j+1)<<1)),f);
                            }
                            hs[p].add(sta,f-1);
                        }
                    }
                }
                else if(left==0 && up==0){
                    hs[p].add(sta,f-1);
                }
            }
        }
        shift(p);
        hs[p=!p].init();
    }
    p=!p;
    for(i=0;i<hs[p].size;i++){
        if(hs[p].sta[i]==0)return hs[p].f[i]-2;
    }
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    while(~scanf("%d%d",&n,&m) && (n || m))
    {
        mem(g,0);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&g[i][j]);
                if(g[i][j]==0)g[i][j]=1;
                else if(g[i][j]==1)g[i][j]=0;
            }
        }

        ans=slove();

        printf("%d\n",ans);
    }
    return 0;
}