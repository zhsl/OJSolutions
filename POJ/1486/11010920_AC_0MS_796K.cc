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
const int MAX=120,INF=200000000;
struct Node{
    int x,y;
}nod[MAX];
struct Square{
    int x1,y1,x2,y2;
}squ[MAX];

int lef[MAX][MAX],righ[MAX][MAX],ans[MAX];
int n;

void getG()
{
    int i,j;
    mem(lef,0);
    mem(righ,0);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(nod[j].x>squ[i].x1&&nod[j].x<squ[i].x2
               && nod[j].y>squ[i].y1&&nod[j].y<squ[i].y2){
                lef[i][0]++;
                righ[j][0]++;
                lef[i][j]=righ[j][i]=1;
            }
        }
    }
}

void greedy()
{
    int i,j,flag=1,cou=0,k;
    mem(ans,0);
    while(flag){
        flag=0;
        for(i=1;i<=n;i++){
            if(lef[i][0]==1){
                flag=1;
                for(j=1;j<=n && !lef[i][j];j++);
                ans[i]=j;
                for(k=1;k<=n;k++){
                    if(lef[k][j])lef[k][0]--,lef[k][j]=0;
                    if(righ[k][i])righ[k][0]--,righ[k][i]=0;
                }
                lef[i][0]=0;
                righ[j][0]=0;
            }
            if(righ[i][0]==1){
                flag=1;
                for(j=1;j<=n && !righ[i][j];j++);
                ans[j]=i;
                for(k=1;k<=n;k++){
                    if(lef[k][i])lef[k][0]--,lef[k][i]=0;
                    if(righ[k][j])righ[k][0]--,righ[k][j]=0;
                }
                lef[j][0]=0;
                righ[i][0]=0;
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int i,j,k=1,flag;
    while(~scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d%d%d",&squ[i].x1,&squ[i].x2,&squ[i].y1,&squ[i].y2);
        for(i=1;i<=n;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);

        getG();
        greedy();

        printf("Heap %d\n",k++);
        for(i=1,flag=0;i<=n;i++){
            if(ans[i]){
                if(flag)printf(" (%c,%d)",i+'A'-1,ans[i]);
                else {
                    flag=1;
                    printf("(%c,%d)",i+'A'-1,ans[i]);
                }
            }
        }

        if(!flag) printf("none");
        putchar('\n');
        putchar('\n');
    }
    return 0;
}