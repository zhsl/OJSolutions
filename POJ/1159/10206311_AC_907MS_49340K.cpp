#include<stdio.h>
#include<string.h>
const int MAX=5010;
short int dp[MAX][MAX];
char a[MAX],b[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,n;
	while(~scanf("%d",&n))
	{
		memset(dp,0,sizeof(dp));
		scanf("%s",a);

		for(i=0;i<n;i++)
			b[i]=a[n-i-1];
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
			}
		}

		printf("%d\n",n-dp[n][n]);
	}
	return 0;
}