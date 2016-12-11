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
		if(n*m==0 && n+m!=0)printf("0\n");
		else if(!n & !m)printf("1\n");
		else {
			if(!(m&1))n-=1,m-=1;
			if(n*m==0 && n+m!=0)printf("0\n");
	    	else if(!n & !m)printf("1\n");
			else {
				n-=(m+1)/2,m=(m-1)/2;
				printf("%d\n",(f(n)==f(n-m)+f(m))?1:0);
			}
		}
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