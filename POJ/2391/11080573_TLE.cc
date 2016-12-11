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
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=210,INF=0x3f3f3f3f;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

struct Edge{
    int u,v,cap;
}e[MAX*MAX*2];

LL w[MAX][MAX],d[MAX*2];
int first[MAX*2],next[MAX*MAX*2],p[MAX*2];
int wt[MAX][MAX],cur[MAX*2],num[MAX*2],nod[MAX][2],inq[MAX];
int n,m,s,t,mt,tar,hav;
LL maxlen,minlen;

void adde(int a,int b,int val)
{
    e[mt].u=a;e[mt].v=b;
    e[mt].cap=val;
    next[mt]=first[a];first[a]=mt++;
    e[mt].u=b;e[mt].v=a;
    e[mt].cap=0;
    next[mt]=first[b];first[b]=mt++;
}

void spfa(int s)
{
    int i,x;
    queue<int> q;
    mem(inq,0);
    mem(d,0x3f);
    d[s]=0;
    q.push(s);
    while(!q.empty()){
        x=q.front();q.pop();
        inq[x]=0;
        for(i=1;i<=n;i++){
            if(wt[x][i] && d[x]+wt[x][i]<d[i]){
                d[i]=d[x]+wt[x][i];
                if(!inq[i]){
                    inq[i]=1;
                    q.push(i);
                }
            }
        }
    }
}

int augment()
{
    int x=t,a=INF;
    while(x!=s){
        a=Min(a,e[p[x]].cap);
        x=e[p[x]].u;
    }
    x=t;
    while(x!=s){
        e[p[x]].cap-=a;
        e[p[x]^1].cap+=a;
        x=e[p[x]].u;
    }
    return a;
}

int isap()
{
    int i,flow=0,x,ok;
    mem(d,0);mem(num,0);
    num[0]=t+1;
    for(i=0;i<=t;i++)cur[i]=first[i];
    x=s;
    while(d[s]<=t){
        if(x==t){
            flow+=augment();
            x=s;
        }
        ok=0;
        for(i=cur[x];i!=-1;i=next[i]){
            if(e[i].cap && d[x]==d[e[i].v]+1){
                ok=1;
                p[e[i].v]=i;
                cur[x]=i;
                x=e[i].v;
                break;
            }
        }
        if(!ok){
            int m=t;
            for(i=first[x];i!=-1;i=next[i])
                if(e[i].cap && d[e[i].v]<m)m=d[e[i].v];
            if(--num[d[x]]==0)break;
            num[d[x]=m+1]++;
            cur[x]=first[x];
            x=e[p[x]].u;
        }
    }
    return flow;
}

LL binary()
{
    int i,j,ok=0;
    LL low=minlen-1,high=maxlen+1,mid;
    while(low<high){
        mid=(low+high)>>1;
        mt=0;
        mem(first,-1);
        for(i=1;i<=n;i++){
            if(nod[i][0])adde(s,i,nod[i][0]);
            adde(n+i,t,nod[i][1]);
        for(j=1;j<=n;j++)
                if(w[i][j]<=mid && nod[i][0])
                    adde(i,n+j,nod[i][0]);
        }
        /*
        for(i=0;i<=t;i++){
            printf("%d   ",i);
            for(j=first[i];j!=-1;j=next[j])
                printf("%d ",e[j].v);
            putchar('\n');
        }
        */
        int tt=isap();
        if(tt<tar)low=mid+1;
        else {
            if(tt==tar)ok=1;
            high=mid;
        }
    }
    return ok?low:-1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,a,b,val;
    LL ans;
    while(~scanf("%d%d",&n,&m))
    {
        tar=hav=0;
        s=0;t=2*n+1;
        maxlen=-LLNF,minlen=LLNF;
        mem(w,0x3f);
        mem(wt,0);
        for(i=1;i<=n;i++){
            scanf("%d%d",&nod[i][0],&nod[i][1]);
            tar+=nod[i][0];hav+=nod[i][1];
        }
        if(tar<=hav){
            for(i=0;i<m;i++){
                scanf("%d%d%d",&a,&b,&val);
                if(!wt[a][b] || val<wt[a][b])wt[a][b]=wt[b][a]=val;
            }
            for(i=1;i<=n;i++){
                spfa(i);
                for(j=1;j<=n;j++){
                    if(d[j]!=LLNF)w[j][i]=d[j];
                    if(d[j]<minlen && i!=j)minlen=d[j];
                    if(d[j]>maxlen && d[j]!=LLNF)maxlen=d[j];
                }
            }
            /*
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++)
                    printf("%4d",w[i][j]);
                putchar('\n');
            }putchar('\n');
            */
            ans=binary();
        }
        else {
            ans=-1;
            while(m--)scanf("%d%d%d",&a,&a,&a);
        }

        printf("%I64d\n",ans);
    }
    return 0;
}