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
const int N=32,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

int dx[4]={1,1,-1,-1},dy[4]={1,-1,-1,1};
int f[2][N][N],ma[11][N][N],lxy[N][2],cou;
int n,d,m;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int dist(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,ans,t,x,y,p,end,dir,nx,ny,q;
    while(~scanf("%d%d%d",&n,&d,&m) && (n||d||m))
    {
        end=-INF;
        mem(ma,0);
        mem(f,0);
        while(m--){
            scanf("%d%d%d",&x,&y,&t);
            if(t>end)end=t;
            ma[t][x+d][y+d]=1;
        }
        for(cou=x=0;x<=d;x++)
            for(y=0;y<=d;y++){
                if(dist(x,y,0,0)>d*d)continue;
                t=gcd(x,y);
                if(t<=1 && x+y){
                    lxy[cou][0]=x;
                    lxy[cou++][1]=y;
                }
            }
        n+=d+1;
        d*=d;
        for(k=p=1;k<=end;k++,p=!p){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    f[p][i][j]=Max(f[p][i][j],f[!p][i][j]+ma[k][i][j]);
                    for(dir=0;dir<4;dir++){
                        for(q=0;q<cou;q++){
                            x=lxy[q][0]*dx[dir];
                            y=lxy[q][1]*dy[dir];
                            nx=i+x,ny=j+y;
                            for(t=ma[k][i][j];dist(nx,ny,i,j)<=d
                            && nx>=0&&nx<n && ny>=0&&ny<n;nx+=x,ny+=y){
                                t+=ma[k][nx][ny];
                                f[p][nx][ny]=Max(f[p][nx][ny],f[!p][i][j]+t);
                            }
                        }
                    }
                }
            }
        }

        for(ans=-INF,i=0,p=!p;i<n;i++)
            for(j=0;j<n;j++)
                if(f[p][i][j]>ans)ans=f[p][i][j];

        printf("%d\n",ans);
    }
    return 0;
}