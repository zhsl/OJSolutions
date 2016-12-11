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
typedef long long LL;
typedef unsigned long long ULL;
//const
const int N=1500000;
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
 
struct Node{
    int sta[9];
    int d,val;
}s;
 
int vis[N],fa[N][2],f[12],ans[N];
int ma[15],p;
int op[9][9]={
    {0,1,3,4},
    {0,1,2},
    {1,2,4,5},
    {0,3,6},
    {1,3,4,5,7},
    {2,5,8},
    {3,4,6,7},
    {6,7,8},
    {4,5,7,8}
};
int all[9]={4,3,4,3,5,3,4,3,4};
 
void getval(Node &a)
{
    int i;
    a.val=0;
    for(i=0;i<9;i++){
        a.val+=a.sta[i]*f[i];
    }
   // printf(" %d\n",a.val);
}
 
int bfs()
{
    int i,j,sum,w;
    queue<Node> q;
    q.push(s);
    Node t;
    while(!q.empty())
    {
        s=q.front();q.pop();
        for(i=0;i<9;i++){
            t=s;
            for(j=0;j<all[i];j++){
                w=op[i][j];
                t.sta[w]=(t.sta[w]+1)%4;
            }
            for(j=sum=0;j<9;j++)sum+=t.sta[j];
            getval(t);
            if(!vis[t.val]){
                vis[t.val]=1;
                fa[t.val][0]=s.val;
                fa[t.val][1]=i+1;
                t.d++;
                q.push(t);
            }
        //    printf(" %d %d\n",sum,t.val);
            if(sum==27){
                p=t.val;
                return t.val;
            }
        }
    }
}
 
int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,cnt;
    ma[3]=0,ma[6]=1,ma[9]=2,ma[12]=3;
    f[0]=1;
    for(i=1;i<=10;i++)f[i]=f[i-1]*4;
    while(~scanf("%d",&s.sta[0]))
    {
        mem(vis,0);
        s.sta[0]=ma[s.sta[0]];
        for(i=1;i<9;i++){
            scanf("%d",&s.sta[i]);
            s.sta[i]=ma[s.sta[i]];
        }
        s.d=0;
        getval(s);
 
        fa[s.val][0]=-1;
        vis[s.val]=1;
 
        bfs();
 
        cnt=0;
        while(fa[p][0]!=-1){
            ans[cnt++]=fa[p][1];
            p=fa[p][0];
        }
        if(cnt)printf("%d",ans[cnt-1]);
        for(i=cnt-2;i>=0;i--){
            printf(" %d",ans[i]);
        }
        putchar('\n');
    }
    return 0;
}