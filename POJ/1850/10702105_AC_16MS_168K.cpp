#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=28,INF=0x7fffffff,MOD=2009;
const double esp=1e-8,DNF=100000;
LL dp[12][MAX];
char s[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,len,ok;
	LL ans;
	dp[0][26]=dp[1][26]=1;
	for(i=1;i<11;i++)
		for(j=1;j<=26-i+1;j++)
			for(k=j+1;k<=26;k++)
				dp[i][j]+=dp[i-1][k];
	while(~scanf("%s",s))
	{
		ans=0;
		len=strlen(s);
		for(i=0,ok=1;i<len-1;i++)
			if(s[i]>=s[i+1]){ok=0;break;}
		if(ok){
			for(i=1;i<=len;i++){
				for(j=1;j<=26;j++)
					ans+=dp[i][j];
			}
			for(i=0;i<len;i++){
				for(j=s[i]-'a'+2;j<=26;j++)
					ans-=dp[len-i][j];
			}
		}
		printf("%I64d\n",ans);
	}
    return 0;
}