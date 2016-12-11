#include<stdio.h>
#define LL long long
int pow_mod(int a,int n,int m)
{
	int q;
	LL ans=1;
	for(q=n;q;q>>=1){
		if(q&1)ans=ans*(LL)a%m;
		a=(LL)a*(LL)a%m;
	}
	return (int)ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int T,a,b,n,m,i,j,ans;
	while(~scanf("%d",&T))
	{
		for(i=0;i<T;i++)
		{
			ans=0;
			scanf("%d%d",&m,&n);
			for(j=0;j<n;j++){
				scanf("%d%d",&a,&b);
				ans=(ans+pow_mod(a,b,m))%m;
			}
			printf("%d\n",ans);
		}
	}

	return 0;
}