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
#define LL long long
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
const int N=5010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;
//
void swap(int& a,int& b){int t=a;a=b;b=t;}
void swap(LL& a,LL& b){LL t=a;a=b;b=t;}
//

struct Node{
    int l,w;
    bool friend operator < (const Node& a,const Node& b){
        if(a.l!=b.l)return a.l<b.l;
        return a.w<b.w;
    }
}c[N];
int A[N],g[N],d[N];
int T,n;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&c[i].l,&c[i].w);
        }
        sort(c,c+n);

        for(i=0;i<n;i++)A[i]=-c[i].w;
        for(i=1;i<=n;i++)g[i]=INF;
        for(i=0;i<n;i++){
            k=lower_bound(g+1,g+n+1,A[i])-g;
            d[i]=k;
            g[k]=A[i];
        }

        printf("%d\n",d[n-1]);
    }
    return 0;
}