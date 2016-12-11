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
const int N=300,M=100000,INF=0x3f3f3f3f,MOD=1000000007;
const double DNF=100000000000;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,n;
    while(~scanf("%d",&n) && n)
    {
        if(n&1){
            printf("%d\n",n-1);
        }
        else printf("No Solution!\n");
    }
    return 0;
}