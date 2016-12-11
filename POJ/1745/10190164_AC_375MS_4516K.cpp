#include<stdio.h>
#include<string.h>
const int MAX=10010;
int num[MAX],dp[MAX][110];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,j;
	while(~scanf("%d%d",&n,&k))
	{
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);

		dp[0][ (num[0]%k+k)%k ]=1;
		for(i=1;i<n;i++){
			for(j=0;j<101;j++){
				if(dp[i-1][j]){
					dp[i][ ((j+num[i])%k+k)%k ]=1;
					dp[i][ ((j-num[i])%k+k)%k ]=1;
				}
			}
		}

		printf("%s\n",dp[n-1][0]?"Divisible":"Not divisible");
	}
	return 0;
}