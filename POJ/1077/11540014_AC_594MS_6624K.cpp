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
const int N=210;
const int INF=0x3f3f3f3f;
const int MOD=1000007,STA=400010;
const LL LNF=1LL<<60;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
//Daily Use ...
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
//End

char out[]="urdl";
int fac[10];
int T,end;

struct Path{
    int op,fa;
}path[STA];

struct Node{
    int ma[9];
    int sta,g,h,x,y;
    friend bool operator < (const Node& a,const Node& b){
        return a.g+a.h>b.g+b.h;
    }
};

struct HASH{
    int sta[STA];
    void init(){mem(sta,0);}
    int ctadd(int s[]){
        int i,j,ret=0,k;
        for(i=0;i<9;i++){
            for(j=k=0;j<i;j++)
                if(s[j]<s[i])k++;
            ret+=k*fac[i];
        }
        if(sta[ret])return -1;
        sta[ret]=1;
        return ret;
    }
}hs;

int geth(int s[])
{
    int i,j,h=0,x,y;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            x=s[i*3+j]/3;
            y=s[i+3+j]%3;
            h+=abs(x-i)+abs(y-j);
        }
    }
    return h;
}

int astar(int s[])
{
    int i,j;
    Node u,v;
    priority_queue<Node> q;
    for(i=0;i<9;i++)u.ma[i]=s[i];
    u.sta=hs.ctadd(s);
    u.g=0;u.h=geth(s);
    for(i=0;i<9;i++)if(s[i]==8){u.x=i/3,u.y=i%3;break;}
    q.push(u);
    path[u.sta].fa=-1;
    while(!q.empty()){
        u=q.top();q.pop();
        if(u.sta==end){
            return u.sta;
        }
        for(i=0;i<4;i++){
            v.x=u.x+dx[i];
            v.y=u.y+dy[i];
            if(v.x>=0&&v.x<3 && v.y>=0&&v.y<3){
                for(j=0;j<9;j++)v.ma[j]=u.ma[j];
                v.ma[v.x*3+v.y]=u.ma[u.x*3+u.y];
                v.ma[u.x*3+u.y]=u.ma[v.x*3+v.y];
                v.sta=hs.ctadd(v.ma);
                if(v.sta>=0){
                    path[v.sta].op=i;
                    path[v.sta].fa=u.sta;
                    v.g=u.g+1;
                    u.h=geth(v.ma);
                    q.push(v);
                }
            }
        }
    }
    return -1;
}

void print(int u)
{
    if(path[u].fa==-1)return;
    print(path[u].fa);
    printf("%c",out[path[u].op]);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,s[10],ans;
    char c;
    fac[0]=1;
    for(i=1;i<9;i++)fac[i]=i*fac[i-1];
    for(i=end=0;i<9;i++){end+=i*fac[i];}

    for(i=0;i<9;i++){
        scanf(" %c",&c);
        if(c=='x')s[i]=8;
        else s[i]=c-'1';
    }

    hs.init();
    ans=astar(s);

    if(ans>=0)print(ans);
    else printf("unsolvable\n");
    return 0;
}