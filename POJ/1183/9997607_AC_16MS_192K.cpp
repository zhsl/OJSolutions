#include<stdio.h>
#include<math.h>
int main()
{
	__int64 i,a,ia,m,min,k;
	while(~scanf("%I64d",&a))
	{
		min=0x80000000;
		ia=a*a+1;
		m=(int)ceil(sqrt(ia*1.0));

		for(i=1;i<=a;i++){
			if(ia%i==0){
				if(i<=m)min=2*a+ia/i+i;
				else {
					k=2*a+ia/i+i;
					if(k<min)min=k;
					break;
				}
			}
		}
		printf("%I64d\n",min);
	}
	return 0;
}