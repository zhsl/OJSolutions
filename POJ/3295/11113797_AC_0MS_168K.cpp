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
const int MAX=210,INF=0x3f3f3f3f;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

int vis[MAX];
char str[MAX],s[MAX],w[MAX];
int n;

int dfs(int cur)
{
    if(vis[cur])return dfs(cur+1);
    vis[cur]=1;
    if(s[cur]<2)return s[cur];
    if(s[cur]=='N')return !dfs(cur+1);
    int a,b;
    a=dfs(cur+1);b=dfs(cur+2);
    if(s[cur]=='K')return a&&b;
    if(s[cur]=='A')return a||b;
    if(s[cur]=='C')return !a||b;
    return a==b;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    w['p']=0,w['q']=1,w['r']=2,w['s']=3,w['t']=4;
    int i,j,len,ok;
    n=(1<<5);
    while(~scanf("%s",str) && str[0]!='0')
    {
        len=strlen(str);
        ok=1;
        for(i=0;i<n;i++){
            strcpy(s,str);
            mem(vis,0);
            for(j=0;j<len;j++)
                if(s[j]>='a' && s[j]<='z')s[j]=(i&(1<<w[s[j]]))?1:0;
            if(!dfs(0)){ok=0;break;}
        }
        printf("%s\n",ok?"tautology":"not");
    }
    return 0;
}