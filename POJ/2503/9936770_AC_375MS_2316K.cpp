#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXN=100010;
int judge(char *a,int high);
int cmp_char(const void *a,const void *b);
char map[MAXN][2][11];
int main()
{
//	freopen("in.txt","r",stdin);
	int ok,i;
	char dic[22];
	for(i=0,gets(dic);dic[0]!='\0';i++)
	{
		sscanf(dic,"%s%s",map[i][0],map[i][1]);
		gets(dic);
	}

	qsort(map,i,sizeof(char)*22,cmp_char);

	while(~scanf("%s",dic))
	{
		ok=judge(dic,i);
		printf("%s\n",ok>=0?map[ok][0]:"eh");
	}
	return 0;
}

int judge(char *a,int high)
{
	int low=0,mid,ok;
	while(low<high){
		mid=(low+high)/2;
		ok=strcmp(map[mid][1],a);
		if(!ok)return mid;
		else if(ok>0)high=mid;
		else low=mid+1;
	}
	return -1;
}

int cmp_char(const void *a,const void *b)
{
	return strcmp((char*)a+11,(char*)b+11);
}