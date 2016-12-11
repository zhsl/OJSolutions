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

char op[]="ABCDEFGH";
int ma[8][7]={
    0,2,6,11,15,20,22,
    1,3,8,12,17,21,23,
    10,9,8,7,6,5,4,
    19,18,17,16,15,14,13,
    23,21,17,12,8,3,1,
    22,20,15,11,6,2,0,
    13,14,15,16,17,18,19,
    4,5,6,7,8,9,10,
};
int r[]={5,4,7,6,1,0,3,2};
int mid[]={6,7,8,11,12,15,16,17};
int path[N],s[24];
int depth;

int geth(int s[])
{
    int i,cnt[]={0,0,0,0};
    for(i=0;i<8;i++){
        cnt[s[mid[i]]]++;
    }
    return 8-Max(cnt[1],cnt[2],cnt[3]);
}

void move(int op)
{
    int i,t;
    t=s[ma[op][0]];
    for(i=1;i<7;i++){
        s[ma[op][i-1]]=s[ma[op][i]];
    }
    s[ma[op][6]]=t;
}

int idastar(int d)
{
    if(d>=depth)return 0;
    int i,h;
    for(i=0;i<8;i++){
        move(i);
        path[d]=i;
        h=geth(s);
        if(!h)return 1;
        if(d+h<depth && idastar(d+1))return 1;
        move(r[i]);
    }
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i;
    while(~scanf("%d",&s[0]) && s[0])
    {
        for(i=1;i<24;i++)
            scanf("%d",&s[i]);
        depth=geth(s);
        if(!depth){
            printf("No moves needed\n%d\n",s[mid[0]]);
        }
        else {
            while(!idastar(0))depth++;
            for(i=0;i<depth;i++){
                printf("%c",op[path[i]]);
            }
            printf("\n%d\n",s[mid[0]]);
        }
    }
    return 0;
}