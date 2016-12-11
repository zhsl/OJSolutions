#include<stdio.h>
#include<stdlib.h>
const int MAXN=10010;
int cmp(const void *a,const void *b);
int num[MAXN],n;
int main()
{
//	freopen("in.txt","r",stdin);

	int i;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);

		qsort(num,n,sizeof(int),cmp);

		printf("%d\n",num[n/2]);
	}
	return 0;
}

int cmp(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}