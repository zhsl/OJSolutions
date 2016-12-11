#include<stdio.h>
#include<string.h>
const int MAX=100010;
int dp[10][MAX],num[15][2],n,cash;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,ans,t;
	while(~scanf("%d%d",&cash,&n))
	{
		ans=0;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			scanf("%d%d",&num[i][0],&num[i][1]);

		if(n && cash){
			for(i=0;i<=num[0][0];i++){
	     		t=i*num[0][1];
				if(t<=cash){
		     		dp[0][t]=1;
					if(t>ans)ans=t;
				}
				else break;
			}

			for(i=1;i<n;i++){
				for(j=0;j<=cash;j++)
					if(dp[i-1][j]){
						for(k=0;k<=num[i][0];k++){
							t=j+k*num[i][1];
							if(t<=cash){
								dp[i][t]=1;
								if(t>ans)ans=t;
							}
			    			else break;
						}
					}
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}