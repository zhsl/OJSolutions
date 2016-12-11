#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define abs(a) ((a)>0?(a):-(a))
const int N=9,INF=0x3f3f3f3f;

int num[N][N],f[16][N][N][N][N],sv[N][N][N][N],s[N][N];
int n;

void getsv()
{
    int i,j,t,x1,y1,x2,y2;
    for(i=1;i<=8;i++){
        for(j=1,t=0;j<=8;j++){
            t+=num[i][j];
            s[i][j]+=s[i-1][j]+t;
        }
    }
    for(x1=1;x1<=8;x1++)
        for(y1=1;y1<=8;y1++)
            for(x2=x1;x2<=8;x2++)
                for(y2=y1;y2<=8;y2++){
                    sv[x1][y1][x2][y2]=s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
                    sv[x1][y1][x2][y2]*=sv[x1][y1][x2][y2];
                }
}

int dfs(int x1,int y1,int x2,int y2,int cur)
{
    if(cur==1)return sv[x1][y1][x2][y2];
    int& d=f[cur][x1][y1][x2][y2];
    if(d!=INF)return d;
    if( x2-x1+y2-y1<cur )return INF;
    int i;
    for(i=y1+1;i<y2;i++){
        d=Min(d,dfs(x1,y1,x2,i-1,cur-1)+sv[x1][i][x2][y2]);
        d=Min(d,dfs(x1,i,x2,y2,cur-1)+sv[x1][y1][x2][i-1]);
    }
    for(i=x1+1;i<x2;i++){
        d=Min(d,dfs(x1,y1,i-1,y2,cur-1)+sv[i][y1][x2][y2]);
        d=Min(d,dfs(i,y1,x2,y2,cur-1)+sv[x1][y1][i-1][y2]);
    }
    return d;
}


int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,sum=0,x1,y1,x2,y2;;
    double aver=0;
    mem(f,INF);
    scanf("%d",&n);
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++){
            scanf("%d",&num[i][j]);
            sum+=num[i][j];
        }
    aver=(double)sum/n;
    getsv();
    dfs(1,1,8,8,n);

    printf("%.3lf\n",sqrt((f[n][1][1][8][8]-2*sum*aver)/n+aver*aver) );
    return 0;
}