#include<stdio.h>
#include<string.h>
const int MAX=210;
int DFS(int w,int w1,int w2);
int len1,len2,len;
char s1[MAX],s2[MAX],s[MAX+MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,ok,k;	
	scanf("%d",&n);
	for(k=1;n--;k++)
	{
		scanf("%s%s%s",s2,s1,s);
		len1=strlen(s1);
		len2=strlen(s2);
		len=strlen(s);
		
		if(len!=len1+len2 || 
			(s[0]!=s1[0] && s[0]!=s2[0]) ||
			(s[len-1]!=s1[len1-1] && s[len-1]!=s2[len2-1]) )ok=0;
		else ok=DFS(0,0,0);

		printf("Data set %d: %s\n",k,ok?"yes":"no");
	}
	return 0;
}

int DFS(int w,int w1,int w2)
{
	if(w==len)return 1;
	if(w1<len1 && s1[w1]==s[w]){
		if(DFS(w+1,w1+1,w2))return 1;
	}
	if(w2<len2 && s2[w2]==s[w]){
		if(DFS(w+1,w1,w2+1))return 1;
	}
	return 0;
}