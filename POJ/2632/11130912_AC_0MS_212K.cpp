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
const int MAX=110,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

struct Node{
    int x,y,r;
}nod[MAX];

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char ma[128];
int g[MAX][MAX];
int T,w,h,n,m,ans1,ans2;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,ans,dir,nx,ny;
    char s[2];
    ma['N']=0,ma['E']=1,ma['S']=2,ma['W']=3;
    scanf("%d",&T);
    while(T--){
        ans=0;
        mem(g,0);
        scanf("%d%d%d%d",&w,&h,&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d%d%s",&nod[i].x,&nod[i].y,s);
            g[nod[i].x][nod[i].y]=i;
            nod[i].r=ma[s[0]];
        }
        for(i=0;i<m;i++){
            scanf("%d%s%d",&a,s,&b);
            if(s[0]=='F'){
                dir=nod[a].r;
                while(b--){
                    nx=nod[a].x+dx[dir];
                    ny=nod[a].y+dy[dir];
                    if(nx<1 || nx>w || ny<1 || ny>h){
                        ans=1;ans1=a;
                        break;
                    }
                    if(g[nx][ny]){
                        ans=2;ans1=a;ans2=g[nx][ny];
                        break;
                    }
                    g[nod[a].x][nod[a].y]=0;
                    g[nx][ny]=a;
                    nod[a].x=nx,nod[a].y=ny;
                }
            }
            else if(s[0]=='L')
                nod[a].r=(nod[a].r-b%4+4)%4;
            else nod[a].r=(nod[a].r+b)%4;
            if(ans)break;
        }
        for(i++;i<m;i++)
            scanf("%d%s%d",&a,s,&b);

        if(!ans)printf("OK\n");
        else if(ans==1)printf("Robot %d crashes into the wall\n",ans1);
        else printf("Robot %d crashes into robot %d\n",ans1,ans2);
    }
    return 0;
}