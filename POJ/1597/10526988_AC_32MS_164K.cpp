#include<stdio.h>
#include<string.h>
const int MAX=100010;
int main()
{
	int s,s1,s2,m,k;
	while(~scanf("%d%d",&s,&m))
	{
		k=1;
		s1=0;
		while(1){
			s2=(s1+s)%m;
			s1=s2;
			if(!s1)break;
			k++;
		}
		printf("%10d%10d    %s\n\n",s,m,k==m?"Good Choice":"Bad Choice");
	}
	return 0;
}