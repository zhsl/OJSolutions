#include<stdio.h>
#include<string.h>
const int MAX1=100010,MAX2=1010;
int dp[MAX1],num[MAX2][2],n,cash;
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

		dp[0]=1;
		for(i=0;i<n;i++){
			for(j=0;j<=cash;j++){
				if(dp[j])
					for(k=0;k<=num[i][0];k++){
						t=j+k*num[i][1];
						if(t<=cash){
							dp[t]=1;
							if(t>ans)ans=t;
						}
			    		else break;
					}
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}