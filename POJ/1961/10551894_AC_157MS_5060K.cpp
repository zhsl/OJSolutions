#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define LL __int64
const int MAX=1000010,INF=1000000000;
int getnext(char *a);
int n,next[MAX];
char c[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,k=1,l;
	while(scanf("%d",&n) && n)
	{
		scanf("%s",c);
		getnext(c);
		printf("Test case #%d\n",k++);
		for(i=2;i<=n;i++){
			l=i-next[i];
			if(i%l==0 && i!=l)
				printf("%d %d\n",i,i/l);
		}
		putchar('\n');
	}
	return 0;
}

int getnext(char *a)
{
	int k=-1,i=0;
	next[0]=-1;
	while(i<n){
		if(k==-1 || a[k]==a[i])
			next[++i]=++k;
		else k=next[k];
	}
	return 1;
}