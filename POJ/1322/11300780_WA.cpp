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
#define pdi pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=110,INF=0x3f3f3f3f,MOD=100000000;
const double esp=0.00001;

double f[2][N];
int c,n,m;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,p,ok;
    double la[N];
    while(~scanf("%d%d%d",&c,&n,&m) && c)
    {
        if(m>c || m>n || (n+m)&1){
            printf("0.000\n");
            continue;
        }
        mem(la,0);
        mem(f,0);
        f[0][0]=p=1;
        while(n--){
            f[p][0]=f[!p][1]/c;
            for(i=1;i<=c;i++)
                f[p][i]=f[!p][i-1]*(c-i+1)/c+f[!p][i+1]*(i+1)/c;
            for(i=0,ok=1;i<=c;i+=2)
                if(fabs(f[p][i]-la[i])>esp || !f[p][i]){ok=0;break;}
            if(ok)break;
            for(i=0;i<=c;i++)la[i]=f[!p][i];
            p=!p;
        }
        if(n<0)n++;
        printf("%.3lf\n",f[n&1][m]);
    }
    return 0;
}