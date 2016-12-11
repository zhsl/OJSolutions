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
const int N=110,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int n;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,a,t;
    LL ans;
    while(~scanf("%d",&n))
    {
        priority_queue<int,vector<int>,greater<int> > q;
        ans=0;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            q.push(a);
        }
        for(i=1;i<n;i++){
            t=q.top();q.pop();
            t+=q.top();q.pop();
            ans+=t;
            q.push(t);
        }

        printf("%I64d\n",ans);
    }
    return 0;
}