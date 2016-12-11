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
const int MAX=55,INF=0x3f3f3f3f;

int map[MAX][MAX][MAX],sker[MAX][MAX],sto[MAX][MAX],lx[MAX*3],ly[MAX*3];
int S[MAX*3],T[MAX*3],y[MAX*3],need[MAX],hav[MAX],w[MAX*3][MAX*3];
int n,m,k,slack,nt,mt;

int dfs(int u)
{
    S[u]=1;
    int v,t;
    for(v=0;v<mt;v++){
        t=w[u][v]-lx[u]-ly[v];
        if(!t){
            if(!T[v]){
                T[v]=1;
                if(y[v]==-1 || dfs(y[v])){
                    y[v]=u;
                    return 1;
                }
            }
        }
        else if(t<slack)slack=t;
    }
    return 0;
}

int KM()
{
    int i,j,s;
    mem(y,-1);
    mem(ly,0);
    for(i=0;i<nt;i++){
        lx[i]=INF;
        for(j=0;j<mt;j++)
            if(w[i][j]<lx[i])lx[i]=w[i][j];
    }
    for(i=0;i<nt;i++){
        while(1){
            mem(S,0);mem(T,0);
            slack=INF;
            if(dfs(i))break;
            for(j=0;j<nt;j++)if(S[j])lx[j]+=slack;
            for(j=0;j<mt;j++)if(T[j])ly[j]-=slack;
        }
    }
    for(i=s=0;i<mt;i++)
        if(y[i]!=-1)s+=w[y[i]][i];
    return s;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,p,ans,ok;
    while(~scanf("%d%d%d",&n,&m,&k) && (n||m||k))
    {
        ok=1;
        ans=0;
        mem(need,0);
        mem(hav,0);
        for(i=0;i<n;i++)
            for(j=0;j<k;j++){
                scanf("%d",&sker[j][i]);
                need[j]+=sker[j][i];
            }
        for(i=0;i<m;i++)
            for(j=0;j<k;j++){
                scanf("%d",&sto[j][i]);
                hav[j]+=sto[j][i];
            }
        for(p=0;p<k;p++)
            for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                    scanf("%d",&map[p][i][j]);

        for(i=0;i<k;i++)
            if(need[i]>hav[i]){ok=0;break;}
        if(ok){
            for(p=0;p<k;p++){
                nt=mt=0;
                for(i=0;i<n;i++)
                    while(sker[p][i]--)S[nt++]=i;
                for(i=0;i<m;i++)
                    while(sto[p][i]--)T[mt++]=i;
                for(i=0;i<nt;i++)
                    for(j=0;j<mt;j++)
                        w[i][j]=map[p][S[i]][T[j]];
                ans+=KM();
            }
        }

        if(ok)printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}