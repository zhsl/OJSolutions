#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=1010,INF=0x7fffffff,MOD=2009;
const double esp=1e-8,DNF=100000;
int getnext();
int next[MAX];
char s[MAX],c[4]="you";
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,len,w;
	getnext();
	while(gets(s)!=NULL)
	{
		w=0;
		len=strlen(s);
		for(i=j=0;i<len;i++){
			if(s[i]!=c[j] && j>0)j=next[j];
			else if(s[i]==c[j])j++;
			if(j==3){//&& ( i-3<0 || s[i-3]==' ') && (i+1==len || s[i+1]==' ')){
				for(;w<i-2;w++)
					printf("%c",s[w]);
				printf("we");
				w=i+1;
				j=0;
			}
		}
		for(;w<len;w++)
			printf("%c",s[w]);
		putchar('\n');
	}
    return 0;
}

int getnext()
{
	int i=0,k=-1;
	next[0]=-1;
	for(i=0;i<3;i++)
		if(k==-1 || c[k]==c[i])
			next[++i]=++k;
		else 
			k=next[k];
	return 1;
}