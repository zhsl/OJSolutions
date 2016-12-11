#include<stdio.h>
#define LL __int64
int is_prime(int a)
{
	int i;
	for(i=2;i*i<a;i++)
		if(a%i==0)
			return 0;
	return 1;
}
int pow(int a,int n,int m)
{
	int p;
	LL ans=1;
	for(p=n;p;p>>=1){
		if(p&1)ans=ans*(LL)a%m;
		a=(LL)a*(LL)a%m;
	}
	return (int)ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int i,a,p,ok;
	while(~scanf("%d%d",&p,&a) && a&&p)
	{
		ok=is_prime(p);
		ok=!ok;
		if(ok)
			ok=pow(a,p,p)==a?1:0;
		printf("%s\n",ok?"yes":"no");
	}
	return 0;
}