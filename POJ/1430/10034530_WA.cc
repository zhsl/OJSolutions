#include<stdio.h>
__int64 f(__int64 a);
int main()
{
//	freopen("in.txt","r",stdin);
	__int64 t,n,m;
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&m);
		n-=m;
		m=(m-1)/2;
		printf("%I64d\n",(f(n+m)==f(m)+f(n))?1:0);
	}
	return 0;
}

__int64 f(__int64 a)
{
	__int64 k=0;
	while(a)
	{
		a/=2;
		k+=a;
	}
	return k;
}