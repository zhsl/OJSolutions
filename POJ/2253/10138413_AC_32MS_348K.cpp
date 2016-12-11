
#include<stdio.h>
#include<math.h>
const int MAX=210,INF=0x7fffffff;
int w[MAX][MAX],d[MAX],n,map[MAX][2];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t,x,y;
	for(k=1;scanf("%d",&n) && n;k++)
	{
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
			for(x=0;x<n;x++){
				for(y=0;y<n;y++){
					t=d[x]>w[x][y]?d[x]:w[x][y];
					d[y]=(d[y]<t?d[y]:t);
				}
			}
		}

		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",k,sqrt((double)d[1]));
	}
	return 0;
}