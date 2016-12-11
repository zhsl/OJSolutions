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
const int N=210,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;

LL a[N],m[N];
int num[N][N],A[N][N],D[N][N],vis[N],vis2[N];
int n,p;

void exgcd(LL a,LL b,LL& d,LL& x,LL& y)
{
    if(!b){d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

LL Modline(int n)
{
    LL d,x,y,A,M,Mod;
    A=a[n-1],M=m[n-1];
    n--;
    // m1*x-m2*y=a2-a1
    while(n--){
        exgcd(M,m[n],d,x,y);
        if((A-a[n])%d!=0){
            return -1;
        }
        Mod=m[n]/d;
        x=(x*((a[n]-A)/d)%Mod+Mod)%Mod;
        A+=M*x;
        M=M/d*m[n];
    }
    return A;
}

int find(int T[],int C[])
{
    int i,j,u,cnt=0,d,l,t,ok;
    mem(vis,0);
    for(i=0;i<n;i++){
        if(!vis[i]){
            l=-1,d=0;u=i;
            while(!vis[u]){
                vis[u]=1;
                mem(vis2,0);
                for(t=ok=0,j=u;!vis2[j];t++,j=T[j]){
                    vis2[j]=1;
                    if(j==C[u]){ok=1;break;}
                }
                if(l==-1)l=t;
                if(!ok || l!=t)return 0;
                u=C[u];
                d++;
            }
            a[cnt]=l,m[cnt++]=d;
        }
    }
    return cnt;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    LL ans,x,t;
    while(~scanf("%d%d",&n,&p))
    {
        for(i=0;i<n;i++){
            for(j=0;j<p;j++){
                scanf("%d",&num[j][i]);
                num[j][i]--;
            }
        }
        for(i=0;i<n;i++)A[0][i]=num[0][i];
        for(i=1;i<p;i++){
            for(j=0;j<n;j++){
                A[i][j]=num[i][A[i-1][j]];
            }
        }
        for(i=0;i<p;i++){
            for(j=0;j<n;j++){
                D[i][A[i][j]]=j;
            }
        }

        ans=LNF;
        for(i=0;i<p;i++){
            if(t=find(A[p-1],D[i])){
                if((x=Modline(t))!=-1){
                    ans=Min(ans,x*p+i+1);
                    if(ans>=1e9){ans=LNF;break;}
                }
            }
        }

        if(ans!=LNF)printf("%I64d\n",ans);
        else printf("No one knows.\n");
    }
    return 0;
}