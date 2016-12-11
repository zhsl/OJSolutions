#include<stdio.h>
#include<string.h>
int num,dp[2][110];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,j;
	while(~scanf("%d%d",&n,&k))
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&num);
		dp[0][ (num%k+k)%k ]=1;

		for(i=1;i<n;i++){
			scanf("%d",&num);
			for(j=0;j<101;j++){
				if(dp[0][j]){
					dp[1][ ((j+num)%k+k)%k ]=1;
					dp[1][ ((j-num)%k+k)%k ]=1;
				}
			}
			for(j=0;j<101;j++){
				dp[0][j]=dp[1][j];
				dp[1][j]=0;
			}
		}
		printf("%s\n",dp[0][0]?"Divisible":"Not divisible");
	}
	return 0;
}