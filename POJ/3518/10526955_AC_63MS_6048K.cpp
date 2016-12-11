#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAX=1500000;
int prime[MAX];
int k;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t,ans;
	memset(prime,0,sizeof(prime));
	t=(int)sqrt(1500000.0);
	for(i=2;i<=t;i++){
		if(!prime[i])
			for(j=i+i;j<=MAX;j+=i)
				prime[j]=1;
	}
	while(scanf("%d",&k) && k)
	{
		ans=0;
		if(prime[k]){
			for(i=k;prime[i];i--)ans++;
			for(i=k+1;prime[i];i++)ans++;
		}
		else ans=-1;
		printf("%d\n",ans+1);
	}
	return 0;
}