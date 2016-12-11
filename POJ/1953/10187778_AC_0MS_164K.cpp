#include<stdio.h>
const int MAX=50;
int f[MAX];
int main()
{
	int i,a,n,k;
	f[1]=2,f[2]=3;
	for(i=3;i<46;i++)
		f[i]=f[i-1]+f[i-2];
	scanf("%d",&n);
	for(k=1;n--;k++)
	{
		scanf("%d",&a);
		printf("Scenario #%d:\n%d\n\n",k,f[a]);
	}
	return 0;
}