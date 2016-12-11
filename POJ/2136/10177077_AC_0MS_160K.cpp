#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

struct set
{
	int num;
	int end;
	bool end1;
};
set ans[27];
char a[4][80];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,j,k,max=0,t=0;
	for(i=0;i<4;i++)
		gets(a[i]);
	for(i=0;i<4;i++)
	{
		int len=strlen(a[i]);
		for(j=0;j<len;j++)
		{
			if(a[i][j]>='A' && a[i][j]<='Z')
				ans[a[i][j]-'A'].num++;
		}
	}
	for(i=25;i>=0;i--)
	{
		if(ans[i].num>max)
		{
			ans[i].end=ans[i].num-max;
			max=ans[i].num;
		}
	} 
	for(i=max;i>0;i--)
	{
		for(j=0;j<26;j++)
		{
				printf("%s",ans[j].num-i>=0?"*":" ");
				if(ans[j].end)
				{
					ans[j].end--;
					break;
				}
				else printf(" ");
		}
		printf("\n");
	}
	for(i=0;i<26;i++)
	{
		printf("%c%s",'A'+i,i!=25?" ":"");
	}
    return 0;
}