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
#define pdi pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=30,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;
const double DNF=100000000000;

struct Node{
    int a,id;
}num[N];
int w[N][N];
int T,n;

int cmp(const Node& a,const Node& b)
{
    return a.a>b.a;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ok;
    scanf("%d",&T);
    while(T--)
    {
        ok=1;
        mem(w,0);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num[i].a);
            num[i].id=i;
        }

        for(i=0;i<n;i++){
            sort(num,num+n,cmp);
            for(j=1;j<n && num[0].a;j++){
                if(num[j].a){
                    num[0].a--;num[j].a--;
                    w[num[0].id][num[j].id]=w[num[j].id][num[0].id]=1;
                }
             }
             if(num[0].a){ok=0;break;}
        }

        if(!ok)printf("NO\n");
        else {
            printf("YES\n");
            for(i=0;i<n;i++){
                printf("%d",w[i][0]);
                for(j=1;j<n;j++)
                    printf(" %d",w[i][j]);
                putchar('\n');
            }
        }
        if(T)putchar('\n');
    }
    return 0;
}