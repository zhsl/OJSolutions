#include<stdio.h>
#include<string>
#include<memory.h>
#include<math.h>
void multiply(char *a,int b);
void fanzhuan(char *a);
char r[300];
int k,lenr;
int main()
{
	//freopen("in.in","r",stdin);
	int i,n,b;
	memset(r,'0',300);
	while(scanf("%s%d",r,&n)!=EOF)
	{
		fanzhuan(r);
		for(i=0,b=0;i<lenr;i++)
			b+=(r[i]-'0')*pow(10,i);
		k=n*k-1;
		while(--n)
			multiply(r,b);
		for(i=300;r[--i]=='0';);
		if(i>=0){
			if(i<k)i=k;
	     	for(;i>=0;)
		    	i==k?printf(".%c",r[i--]):printf("%c",r[i--]);
		}
		else printf("0");
		putchar('\n');
		memset(r,'0',300);
	}
	return 0;
}
void multiply(char *a,int b)
{
	int i,t;
	for(i=0,t=0;i<300;i++)
	{
		int s=(r[i]-'0')*b+t;
		r[i]=s%10+'0';
		t=s/10;
	}
}
void fanzhuan(char *a)
{
	int i,j;
	lenr=strlen(a);
	char t[10];
	for(;a[--lenr]=='0';);
	k=lenr;
	strcpy(t,a);
	for(i=0,j=lenr;j>=0;j--)
	{
		if(t[j]!='.')
			a[i++]=t[j];
		else k-=j;
	}
	for(;i<8;a[i++]='0');
}