#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
const int MAX=110;
void jia(int *a0,int *a1,int *a2);
void get(int *a,char *b);
void getvalue(int *a,int *b);
char a[MAX],b[MAX],c[MAX];
int a0[MAX],a1[MAX],a2[MAX],an[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%s%s%s",a,b,c))
	{
		memset(a0,0,sizeof(a0));
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(an,0,sizeof(an));
		get(a0,c);
		get(a1,b);
		get(a2,a);
		for(i=2;i<99;i++){
			jia(a0,a1,a2);
			getvalue(a2,a1);
			getvalue(a1,a0);
			getvalue(a0,an);
		}

		for(i=MAX-1;i>=0 && !a0[i];i--);
		for(;i>=0;i--)
			printf("%d",a0[i]);
		putchar('\n');
	}
	return 0;
}

void get(int *a,char *b)
{
	int i,len;
	len=strlen(b);
	for(i=0;i<len;i++)
		a[len-i-1]=b[i]-'0';
	return;
}

void getvalue(int *a,int *b)
{
	int i;
	for(i=0;i<MAX;i++)
		a[i]=b[i];
}

void jia(int *a0,int *a1,int *a2)
{
	int i,t;
	for(i=t=0;i<MAX;i++){
		an[i]=a0[i]+a1[i]+a2[i]+t;
		t=an[i]/10;
		an[i]%=10;
	}
	return;
}