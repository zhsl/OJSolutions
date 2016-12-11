#include<stdio.h>
#include<string.h>
const int MAX=2010,INF=10;
int prim();
int d[MAX],w[MAX][MAX],vis[MAX],n;
char map[MAX][7];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,ans,cou;
	while(~scanf("%d",&n) && n)
	{
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)
			scanf("%s",map[i]);
		for(i=0;i<n;i++)
			for(j=i;j<n;j++){
				for(k=cou=0;k<7;k++)
					if(map[i][k]!=map[j][k])cou++;
				w[i][j]=w[j][i]=cou;
			}

		ans=prim();

		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}

int prim()
{
	int i,j,x,y,ans=0,m;
	for(i=0;i<n;i++)d[i]=INF;
	d[0]=0;
	for(i=0;i<n;i++){
		m=INF;
		for(j=0;j<n;j++)
			if(!vis[j] && d[j]<m)m=d[x=j];
		vis[x]=1;
		ans+=d[x];
		for(y=0;y<n;y++)
			if(w[x][y] && w[x][y]<d[y])
				d[y]=w[x][y];
	}
	return ans;
}