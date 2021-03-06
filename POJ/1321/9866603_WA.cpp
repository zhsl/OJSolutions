#include<stdio.h>
#include<memory.h>
const int MAXN=18;
int DFS(int y,int cur);
char vis_x[MAXN],vis_emp[MAXN],map[MAXN][MAXN];
int n,k,tot;
int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(scanf("%d%d",&n,&k)&&(n+1))
	{
		tot=0;
		memset(vis_x,0,sizeof(vis_x));
		memset(vis_emp,0,sizeof(vis_emp));

		for(i=0;i<n;i++)
			scanf("%s",map[i]);

		DFS(0,0);

		printf("%d\n",tot);
	}
	return 0;
}

int DFS(int y,int cur)
{
	if(y>=n)return 0;
	for(int i=0;i<n;i++){
		if(map[i][y]=='#'&&!vis_x[i]){
			if(cur+1==k){tot++;continue;};
			vis_x[i]=1;
			DFS(y+1,cur+1);
			vis_x[i]=0;
		}
		else if(map[i][y]=='.'&&!vis_emp[y]){
			vis_emp[y]=1;
			DFS(y+1,cur);
		}
	}
	return 0;
}
