#include<stdio.h>
#include<math.h>
__int64 pa(__int64 a,__int64 b);
int main()
{
//	freopen("in.txt","r",stdin);
	__int64 i,n,p,ok,low,high,k;
	double t;
	while(scanf("%I64d",&n) && n)
	{
		ok=n>0?1:(n=-n,0);
		for(p=0,i=1;i<33;i++){
			t=pow(n,1.0/i);
			low=(__int64)floor(t);
			high=(__int64)ceil(t);
			k=pa(low,i);
			if(k==n && ok){p=i;continue;}
			else if(k==n && (i&1) && !ok){p=i;continue;}
			k=pa(high,i);
			if(k==n && ok){p=i;continue;}
			else if(k==n && (i&1) && !ok){p=i;continue;}
		}
		printf("%I64d\n",p);
	}
	return 0;
}

__int64 pa(__int64 a,__int64 b)
{
	__int64 i,s;
	for(s=1,i=0;i<b;i++)
		s*=a;
	return s;
}