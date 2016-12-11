#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define max(a,b) ( (a>b)?a:b )
const int MAX=1010,INF=100010;
struct Line{
	int u1,u2;
}line[MAX];
struct Node{
	int x,y;
}nod[MAX];
int cmp1(const void *a,const void *b){
	return (*(Line*)a).u1 - (*(Line*)b).u1;
}
int cmp2(const void *a,const void *b){
	return (*(Node*)a).x - (*(Node*)b).x;
}
int get(Line &a,Node &b);
int a[MAX],vis[MAX],ans[MAX];
int n,m,x1,y1,x2,y2;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,max_x;
	while(scanf("%d",&n) && n)
	{
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		for(i=0;i<n;i++)
			scanf("%d%d",&line[i].u1,&line[i].u2);
		for(i=0;i<m;i++)
			scanf("%d%d",&nod[i].x,&nod[i].y);

		qsort(line,n,sizeof(Line),cmp1);
		qsort(nod,m,sizeof(Node),cmp2);

		k=0;
		for(i=0;i<n;i++){
			max_x=max(line[i].u1,line[i].u2);
			for(j=0;nod[j].x<max_x && j<m;j++)
				if(!vis[j] && get(line[i],nod[j]))
					vis[j]=1,a[i]++,k++;
		}
		a[n]=m-k;

		for(i=0;i<=n;i++)
			ans[a[i]]++;
		printf("Box\n");
		for(i=1;i<=m;i++){
			if(ans[i])
				printf("%d: %d\n",i,ans[i]);
		}
	}
	return 0;
}

int get(Line &a,Node &b)
{
	Node r1,r2;
	r1.x=a.u1-a.u2,r1.y=y1-y2;
	r2.x=b.x-a.u2,r2.y=b.y-y2;
	return r1.x*r2.y-r2.x*r1.y>0?1:0;
}