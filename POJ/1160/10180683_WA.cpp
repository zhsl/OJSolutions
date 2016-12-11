#include<stdio.h>
#include<string.h>
#define min(a,b) ( (a)<(b)?(a):(b) )
const int MAX1=310,MAX2=35,INF=10000000;
int dp[MAX1][MAX2],sum[MAX1][MAX2],p[MAX1],P,V;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,min;
	while(~scanf("%d%d",&V,&P))
	{
		min=0x7fffffff;
		memset(sum,0,sizeof(sum));
		for(i=1;i<=V;i++)
			scanf("%d",&p[i]);

		for(i=1;i<V;i++){
			for(j=i+1;j<=V;j++){
				sum[i][j]=sum[i][j-1]+p[j]-p[(i+j)/2];
			}
		}
		for(i=1;i<=V;i++){
			dp[i][1]=sum[1][i];
			dp[i][i]=0;
		}

		for(j=2;j<=P;j++){
			for(i=j+1;i<=V;i++){
				dp[i][j]=INF;
				for(k=j-1;k<i;k++)
		     		dp[i][j]=min(dp[i][j],dp[k][j-1]+sum[k+1][i]);
			}
		}

		printf("%d\n",dp[V][P]);
	}
	return 0;
}