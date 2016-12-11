#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAX=210,INF=0x7fffffff;
int w[MAX][MAX],d[MAX];
int n,map[MAX][MAX],vis[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,min,k;
	int t,x,y;
	for(k=1;scanf("%d",&n) && n;k++)
	{
		memset(w,0,sizeof(w));
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)d[i]=(i==0?0:INF);

		for(i=0;i<n;i++)
			scanf("%d%d",&map[i][0],&map[i][1]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				x=map[j][0]-map[i][0];
				y=map[j][1]-map[i][1];
				t=x*x+y*y;
				w[i][j]=w[j][i]=t;
			}

			for(i=0;i<n;i++){
				for(y=0;y<n;y++){
					min=INF;
					if(!vis[y] && d[y]<min)min=d[x=y];
				}
				vis[x]=1;
				for(y=0;y<n;y++){
					t=d[x]>w[x][y]?d[x]:w[x][y];
					d[y]=(d[y]<t?d[y]:t);	
				}
			}

		printf("Scenario #%d\nFrog Distance = %.3lf\n",k,sqrt((double)d[1]));
	}
	return 0;
}