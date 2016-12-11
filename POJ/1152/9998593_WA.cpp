#include<stdio.h>
#include<string.h>
const int MAX=30010;
char num[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,len,s,max,k,flag;
	while(~scanf("%s",num))
	{
		max=0x80000000;
		len=strlen(num);

		for(s=0,i=0;i<len;i++){
			if(num[i]<=57)k=num[i]-48;
			else if(num[i]<=90)k=num[i]-55;
			else k=num[i]-61;
			s+=k;
			if(k>max)max=k;
		}

		flag=0;
		for(i=k>0?k:1;i<=62;i++)
			if(s%i==0){flag=1;break;}
		if(flag)printf("%d\n",i+1);
		else printf("such number is impossible!\n");
	}
	return 0;
}