#include<stdio.h>
#include<string.h>
const int MAX=100010;
int num[15][2],n,cash;
bool dp[MAX];
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
			for(j=ans;j>=0;j--)
				if(dp[j]){
					for(k=1;k<=num[i][0];k++){
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