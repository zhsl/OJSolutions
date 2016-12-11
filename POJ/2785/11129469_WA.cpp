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
const int MAX=4010,INF=0x3f3f3f3f;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

map<LL,int> mal,mar;
LL  num[MAX][4],g[MAX*MAX];
int n;

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    LL t;
    while(~scanf("%d",&n))
    {
        ans=0;
        mal.clear();
        mar.clear();
        mem(g,0);
        for(i=0;i<n;i++)
            scanf("%I64d%I64d%I64d%I64d",num[i],&num[i][1],num[i]+2,num[i]+3);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                t=num[i][0]+num[j][1];
                if(!mal[t]){
                    mal[t]=1;
                    g[0]++;
                    g[g[0]]=t;
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                t=-num[i][2]-num[j][3];
                mar[t]=1;
            }
        }
        for(i=1;i<=g[0];i++)
            if(mar[g[i]])ans++;

        printf("%d\n",ans);
    }
    return 0;
}