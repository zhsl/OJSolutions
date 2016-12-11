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
	if(cur==k){tot++;return 1;}
	if(y>=n||n-y+cur<k)return 0;
	for(int i=0;i<n;i++){
	//	if(!y&&!vis_emp[0])memset(vis_emp,0,sizeof(vis_emp));
		if(map[i][y]=='#'){
			if(!vis_emp[y]){vis_emp[y]=1;DFS(y+1,cur);if(y)vis_emp[y]=0;}
			if(!vis_x[i]){
		    	vis_x[i]=1;
		    	DFS(y+1,cur+1);
			    vis_x[i]=0;
			}
		}
	}
	return 0;
}