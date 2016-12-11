#include<stdio.h>
#include<string.h>
const int MAX=110;
int DFS(int x,int y);
char map[MAX][MAX];
int vis[MAX][MAX],n,m,ans;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d",&n,&m))
	{
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)
			scanf("%s",map[i]);

		ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				if(map[i][j]=='W' && !vis[i][j])ans++;
				DFS(i,j);
			}

		printf("%d\n",ans);
	}
	return 0;
}

int DFS(int x,int y)
{
	if(vis[x][y] || x<0||x>=n || y<0||y>=m)return 1;
	if(map[x][y]=='W' && !vis[x][y]){
		vis[x][y]=1;
		DFS(x-1,y-1);DFS(x-1,y);DFS(x-1,y+1);
		DFS(x,y-1);             DFS(x,y+1);
		DFS(x+1,y-1);DFS(x+1,y);DFS(x+1,y+1);
	}
	return 1;
}