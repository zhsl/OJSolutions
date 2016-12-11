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
const int N=2010,INF=0x3f3f3f3f,MOD=100000000;
const double DNF=100000000000;

char s[N];
int f[N][N],cost[130][2];
int n,m;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,k;
    char op[2];
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%s",s);
        for(i=0;i<n;i++){
            scanf("%s%d%d",op,&a,&b);
            cost[op[0]][0]=a;
            cost[op[0]][1]=b;
        }
        for(k=1;k<m;k++){
            for(i=0;i+k<m;i++){
                j=i+k;
                f[i][j]=INF;
                f[i][j]=Min(f[i][j],f[i][j-1]+Min(cost[s[j]][0],cost[s[j]][1]));
                f[i][j]=Min(f[i][j],f[i+1][j]+Min(cost[s[i]][0],cost[s[i]][1]));
                if(s[i]==s[j])
                    f[i][j]=Min(f[i][j],f[i+1][j-1]);
          //      printf("%d ",f[i][j]);//
            }
        //    putchar('\n');//
        }
        printf("%d\n",f[0][m-1]);
    }
    return 0;
}