/*
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
const int MAX=510,INF=200000000;

int vis[MAX];
int T,n;
struct Node{
    int t,x1,y1,x2,y2;
}nod[MAX];

int dfs(int u,int tim)
{
    int v,min=INF,minw,t,nt;
    vis[u]=1;
    t=tim+abs(nod[u].x1-nod[u].x2)+abs(nod[u].y1-nod[u].y2);
    for(v=0;v<n;v++){
        if(!vis[v]){
            nt=t+abs(nod[u].x2-nod[v].x1)+abs(nod[u].y2-nod[v].y1)+1;
            if(nt<=nod[v].t && nod[v].t<min){
                min=nt;
                minw=v;
            }
        }
    }
    if(min!=INF)
        dfs(minw,nod[minw].t);
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans;
    char s[8];
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        mem(vis,0);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s%d%d%d%d",s,&nod[i].x1,&nod[i].y1,&nod[i].x2,&nod[i].y2);
            nod[i].t=((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
        }

        for(i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,nod[i].t);
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
*/



#include<cstdio>
 #include<cstring>
 #include<cmath>
 #include<iostream>
 #include<algorithm>
 #include<set>
 #include<map>
 #include<queue>
 #include<vector>
 #include<string>
 #define Min(a,b) a<b?a:b
 #define Max(a,b) a>b?a:b
 #define CL(a,num) memset(a,num,sizeof(a));
 #define eps  1e-6
 #define inf 10001000

 #define ll   __int64

 #define  read()  freopen("data.txt","r",stdin) ;
 const double pi  = acos(-1.0);
 const int maxn = 510;

 using namespace std;
 int n,m,k,num;
 int head[maxn] ;
 int result[maxn],vis[maxn] ;
 int s[maxn],t[maxn] ,a[maxn],b[maxn],c[maxn],d[maxn];
 struct node
 {
     int v;
     int next;
 }p[maxn*maxn];
 int cnt ;
 void add(int u,int v)
 {
     p[cnt].v = v;
     p[cnt].next = head[u];
     head[u] = cnt++ ;
 }
 bool find(int u)
 {

     for(int i = head[u];i!= -1;i = p[i].next)
     {
         int v = p[i].v ;
         if(!vis[v])
         {
             vis[v] = 1 ;
             if(result[v] == -1||find(result[v]))
             {
                 result[v] = u;
                 return true;
             }
         }
     }
     return false ;
 }
 int get()
 {
     int ans= 0;
     CL(result,-1);
     for(int i = 0;i < n;i++)
     {
         CL(vis,0);
         if(find(i))ans++;
     }
     return ans ;
 }
 char str[100] ;
 int main()
 {
         freopen("in.txt","r",stdin);
     int i,j,x,y,T;
     scanf("%d",&T);
     while(T--)
     {
         scanf("%d",&n);

         CL(s,0);
         CL(t,0) ;
         num = 0 ;
         for(i = 0 ; i< n;i++)
         {

             scanf("%d:%d %d %d %d %d",&x,&y,&a[i],&b[i],&c[i],&d[i]);
             s[num] = x*60 + y;
             t[num] = s[num] + abs(c[i] - a[i]) + abs(d[i] - b[i]) ;
             num++ ;

         }
         CL(head,-1);
         cnt = 0 ;
         for(i = 0 ;i < n;i++)
         {
            for(j = i + 1;j < n;j++)
            {
                if(t[i] + abs(a[j] - c[i]) + abs(b[j] - d[i]) < s[j]) add(i,j) ;
            }
         }
         int ans = get() ;

         printf("%d\n",n - ans) ;
     }
 }




