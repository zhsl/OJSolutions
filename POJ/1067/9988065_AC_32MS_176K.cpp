#include<stdio.h>
#include<math.h>
const double x=((sqrt(5.0)+1)/2);
int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,k,ta;
	while(~scanf("%d%d",&a,&b))
	{
		if(a>b){int t=a;a=b,b=t;}
		k=b-a;
		ta=(int)floor(k*x);
		printf("%d\n",ta==a?0:1);
	}
	return 0;
}