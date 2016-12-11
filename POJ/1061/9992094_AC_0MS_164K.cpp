#include<stdio.h>
void extgcd(__int64 a,__int64 b);
__int64 gcd,x1,x2;
int main()
{
//	freopen("in.txt","r",stdin);
	__int64 x,y,m,n,L,a,b,k,c,t;
	while(~scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L))
	{
		c=y-x,a=m-n,b=L;
		extgcd(a,b);

		if(c%gcd)printf("%Impossible\n");
		else{
			x1*=(c/gcd),x2*=(c/gcd);
		    k=-x1/b*gcd;
		    x1+=b/gcd*k;
			if(x1<0){t=b/gcd;x1+=t<0?-t:t;}
			printf("%I64d\n",x1);
		}
	}
	return 0;
}

void extgcd(__int64 a,__int64 b)
{
	if(!b){
		x1=1;
		x2=0;
		gcd=a;
	}
	else{
		extgcd(b,a%b);
		__int64 t=x1;
		x1=x2;
		x2=t-(a/b)*x2;
	}
}