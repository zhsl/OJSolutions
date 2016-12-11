#include<stdio.h>
#include<memory.h>
const int MAXN=18;
int DFS(int y,int cur);
char vis_x[MAXN],map[MAXN][MAXN];
int n,k,tot;
int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(scanf("%d%d",&n,&k)&&(n+1))
	{
		tot=0;
		memset(vis_x,0,sizeof(vis_x));

		for(i=0;i<n;i++)
			scanf("%s",map[i]);

		DFS(0,0);

		printf("%d\n",tot);
	}
	return 0;
}

int DFS(int y,int cur)
{
	int i;
	if(y>=n||n-y+cur<k)return 0;
	for(i=0;i<n;i++){
		if(map[i][y]=='#'&&!vis_x[i]){
			if(cur+1==k){tot++;continue;}
		   	vis_x[i]=1;
		   	DFS(y+1,cur+1);
		    vis_x[i]=0;
		}
	}
	if(i==n)DFS(y+1,cur);
	return 0;
}