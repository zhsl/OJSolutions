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
#include<set>
using namespace std;
//define
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
//typedef
typedef __int64 LL;
typedef unsigned __int64 ULL;
//const
const int N=1010;
const int INF=0x3f3f3f3f;
const int MOD=100000,STA=8000010;
const LL LNF=1LL<<60;
const double EPS=1e-8;
const double OO=1e15;
//Daily Use ...
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
char ma[]="ABCDEFGH";
char s[N][N],temp[N];
int ch[N*300][26];
int val[N*300],f[N*300],last[N*300],ans[N][3],len[N];
int sz,n,m,w;

void init(){sz=1;mem(ch[0],0);}
inline int idx(char c){return c-'A';}
void insert(char *s,int v){
    int i,len=strlen(s),id,u=0;
    for(i=0;i<len;i++){
        id=idx(s[i]);
        if(!ch[u][id]){
            mem(ch[sz],0);
            val[sz]=0;
            ch[u][id]=sz++;
        }
        u=ch[u][id];
    }
    val[u]=v;
}

void getFail()
{
    int u,c,r;
    queue<int> q;
    f[0]=0;
    for(c=0;c<26;c++){
        u=ch[0][c];
        if(u){f[u]=0;last[u]=0;q.push(u);}
    }
    while(!q.empty()){
        r=q.front();q.pop();
        for(c=0;c<26;c++){
            u=ch[r][c];
            if(!u){ch[r][c]=ch[f[r]][c];continue;}
            q.push(u);
            f[u]=ch[f[r]][c];
            last[u]=val[f[u]]?f[u]:last[f[u]];
        }
    }
}

void judge(int u,int x,int y,int dir)
{
    if(u){
        int nx,ny,v=val[u];
        nx=x-dx[dir]*(len[v]-1);
        ny=y-dy[dir]*(len[v]-1);
        if(nx<ans[v][0] || ( nx==ans[v][0] && ny<ans[v][1] )
           || (nx==ans[v][0] && ny==ans[v][1] && dir<ans[v][2]) ){
            ans[v][0]=nx;
            ans[v][1]=ny;
            ans[v][2]=dir;
        }
        judge(last[u],x,y,dir);
    }
}

void find(int x,int y,int dir)
{
    int c,u;
    for(u=0;x>=0&&x<n && y>=0&&y<m;x+=dx[dir],y+=dy[dir]){
        c=idx(s[x][y]);
        u=ch[u][c];
        if(val[u]){judge(u,x,y,dir);}
        else if(last[u]){judge(last[u],x,y,dir);}
    }
}

void slove()
{
    int i;
    for(i=0;i<m;i++){
        find(0,i,4);find(0,i,3);find(0,i,5);
        find(n-1,i,0);find(n-1,i,7);find(n-1,i,1);
    }

    for(i=0;i<n;i++){
        find(i,0,2);find(i,0,1);find(i,0,3);
        find(i,m-1,6);find(i,m-1,5);find(i,m-1,7);
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k;
    while(~scanf("%d%d%d",&n,&m,&w))
    {
        mem(ans,INF);
        for(i=0;i<n;i++){
            scanf("%s",s[i]);
        }
        init();
        for(i=1;i<=w;i++){
            scanf("%s",temp);
            len[i]=strlen(temp);
            insert(temp,i);
        }
        getFail();
        slove();

        for(i=1;i<=w;i++){
            printf("%d %d %c\n",ans[i][0],ans[i][1],ma[ans[i][2]]);
        }
    }
    return 0;
}