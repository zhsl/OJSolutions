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
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=240,INF=0x3f3f3f3f;

int inq[MAX],w1[MAX][MAX],w2[MAX][MAX],cap[MAX][MAX],d[MAX],cur[MAX];
int n,m,k,nm,limit,maxlen,s,t;

void spfa(int s)
{
    int i,x;
    mem(d,0x3f);mem(inq,0);
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        x=q.front();q.pop();
        inq[x]=0;
        for(i=1;i<=nm;i++){
            if(w1[x][i] && d[x]+w1[x][i]<=d[i]){
                d[i]=d[x]+w1[x][i];
                if(!inq[i]){
                    inq[i]=1;
                    q.push(i);
                }
            }
        }
    }
}

int bfs()
{
    int x,i;
    queue<int> q;
    q.push(s);
    mem(d,0);
    d[s]=1;
    while(!q.empty()){
        x=q.front();q.pop();
        for(i=1;i<=nm;i++){
            if(w2[x][i] && w2[x][i]<=limit && cap[x][i] && !d[i]){
                d[i]=d[x]+1;
                q.push(i);
            }
        }
    }
    return d[t];
}

int dfs(int x,int a)
{
    if(x==t || a==0)return a;
    int f,flow=0;
    for(int& i=cur[x];i<=nm;i++){
        if(w2[x][i] && w2[x][i]<=limit && d[x]+1==d[i] && (f=dfs(i,Min(a,cap[x][i])))>0){
            cap[x][i]-=f;
            cap[i][x]+=f;
            flow+=f;
            a-=f;
            if(!a)break;
        }
    }
    return flow;
}

int dinic()
{
    int flow=0;
    while(bfs()){
        mem(cur,0);
        flow+=dfs(s,2*INF);
    }
    return flow;
}

int binary()
{
    int i,j,low=1,high=maxlen,mid,t;
    while(low<high){
        mid=(low+high)>>1;
        mem(cap,0);
        for(i=n+1;i<=nm-2;i++)
            for(j=1;j<=n;j++)cap[i][j]=1;
        for(i=nm-1,j=1;j<=n;j++)cap[j][i]=k;
        for(i=nm,j=n+1;j<=nm-2;j++)cap[i][j]=1;
        /*
        for(i=1;i<=nm;i++){
            for(j=1;j<=nm;j++)
                printf("%d ",cap[i][j]);
            putchar('\n');
        }putchar('\n');
        */
        limit=mid;
        t=dinic();
        if(t<m)low=mid+1;
        else high=mid;
    }
    return low;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        nm=n+m;
        s=nm+2,t=nm+1;
        mem(w2,0);
        maxlen=-INF;
        for(i=1;i<=nm;i++)
            for(j=1;j<=nm;j++)
                scanf("%d",&w1[i][j]);

        for(i=1;i<=n;i++){
            spfa(i);
            for(j=1;j<=nm;j++){
                w2[i][j]=w2[j][i]=d[j];
                if(d[j]>maxlen)maxlen=d[j];
            }
        }

        nm+=2;
        for(i=nm-1,j=1;j<=n;j++)
            w2[i][j]=w2[j][i]=1;
        for(i=nm,j=n+1;j<=nm-2;j++)
            w2[i][j]=w2[j][i]=1;

        printf("%d\n",binary());
    }
    return 0;
}
