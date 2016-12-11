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
const int N=100010,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

int f[2][110],h[N],minr[110];
int n,c;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,maxh,ans,t,minl,p;
    while(~scanf("%d%d",&n,&c))
    {
        ans=INF;
        maxh=-INF;
        for(i=0;i<n;i++){
            scanf("%d",&h[i]);
            if(h[i]>maxh)maxh=h[i];
        }
        for(i=h[0];i<=maxh;i++)f[0][i]=(i-h[0])*(i-h[0]);
        for(i=p=1;i<n;i++,p=!p){
            for(minl=INF,j=h[i-1];j<=h[i];j++)
                minl=Min(minl,f[!p][j]+c*(h[i]-j));
            minr[maxh]=f[!p][maxh]+c*(maxh-h[i]);
            for(j=maxh-1;j>=h[i] && j>=h[i-1];j--)
                minr[j]=Min( minr[j+1],f[!p][j]+c*(j-h[i]) );
            for(;j>=h[i];j--)minr[j]=minr[j+1];
            for(j=h[i];j<=maxh;j++,minl+=c){
                if(j>=h[i-1])minl=Min(minl,f[!p][j]);
                f[p][j]=Min( minl,minr[j]-c*(j-h[i]) )+(j-h[i])*(j-h[i]);
            }
        }
        for(p=!p,i=h[n-1];i<=maxh;i++){
            ans=Min(ans,f[p][i]);
        }

        printf("%d\n",ans);
    }
    return 0;
}