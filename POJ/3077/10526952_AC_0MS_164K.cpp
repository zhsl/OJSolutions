#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAX=40;
int a,T;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,t,num[MAX],k;
	scanf("%d",&T);
	while(T--)
	{
		memset(num,0,sizeof(num));
		scanf("%d",&a);
		if(a<=10)
			printf("%d\n",a);
		else{
			for(k=0,t=a;t/=10;k++);
			for(i=0,t=a;i<=k;i++){
				num[i]=t%10;
				t/=10;
			}
			for(i=0,t=0;i<k;i++){
				num[i]+=t;
				if(num[i]>=5)t=1;
				else t=0;
				num[i]=0;
			}
			num[i]+=t;
			if(num[i]==10)num[i]=0,num[i+1]=1;
			for(i=MAX-1;!num[i];i--);
			for(;i>=0;i--)
				printf("%d",num[i]);
			putchar('\n');
		}
	}
	return 0;
}