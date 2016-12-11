#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LL long long
#define pii pair<int,int>
const int MAX=210,INF=1000000010,MOD=7;
int cmp(const void *a,const void *b){
	return *(int*)b - *(int*)a;
}
int DFS(int x);
int tree[MAX][MAX];
int T,n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		while(n--){
			scanf("%d",&i);
			scanf("%d",&tree[i][0]);
			for(j=1;j<=tree[i][0];j++)
				scanf("%d",&tree[i][j]);
		}

		printf("%d\n",DFS(1));
	}
	return 0;
}

int DFS(int x)
{
	if(!tree[x][0])return 1;
	int max,i,num[MAX];
	for(i=1;i<=tree[x][0];i++)
		num[i-1]=DFS(tree[x][i]);
	qsort(num,tree[x][0],sizeof(int),cmp);
	for(i=max=0;i<tree[x][0];i++)
		if(num[i]+i>max)max=num[i]+i;
	return max;
}