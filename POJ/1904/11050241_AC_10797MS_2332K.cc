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
#define LL long long
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=4010,INF=200000000;

vector<int> g[MAX];
stack<int> s;
int sccno[MAX],pre[MAX],low[MAX],ans[MAX];
int n,dfs_clock,scc_cnt;

int dfs(int u)
{
    int i,v;
    pre[u]=low[u]=++dfs_clock;
    s.push(u);
    for(i=0;i<g[u].size();i++){
        v=g[u][i];
        if(!pre[v]){
            dfs(v);
            low[u]=Min(low[u],low[v]);
        }
        else if(!sccno[v]){
            low[u]=Min(low[u],low[v]);
        }
    }
    if(low[u]==pre[u]){
        scc_cnt++;
        while(v!=u){
            v=s.top();s.pop();
            sccno[v]=scc_cnt;
        }
    }
    return low[u];
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,t;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=(n<<1);i++)g[i].clear();
        dfs_clock=scc_cnt=0;
        mem(pre,0);
        mem(sccno,0);
        while(!s.empty())s.pop();
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&t);
                g[i].push_back(t+n);
            }
        }
        for(i=1;i<=n;i++){
            scanf("%d",&t);
            g[t+n].push_back(i);
        }

        for(i=1;i<=n;i++)
            if(!pre[i])dfs(i);

        for(i=1;i<=n;i++){
            mem(ans,0);
            for(j=t=0;j<g[i].size();j++){
                if(sccno[i]==sccno[g[i][j]])
                    ans[t++]=g[i][j]-n;
            }
            sort(ans,ans+t);
            printf("%d",t);
            for(j=0;j<t;j++)
                printf(" %d",ans[j]);
            putchar('\n');
        }
    }
    return 0;
}