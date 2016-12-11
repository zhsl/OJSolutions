#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b);
int num[60][2];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d%d",&num[0][0],&num[0][1]);	
	while(1)
	{	
		for(i=0;k=scanf("%d%d",&num[i][0],&num[i][1]);i++)
			if(!num[i][0]&&!num[i][1] || k==-1)break;
		
		qsort(num,i,sizeof(int)*2,cmp);

		printf("(0,0)\n");
		for(j=0;j<i;j++)
			printf("(%d,%d)\n",num[j][0],num[j][1]);
		if(k==-1)break;
	}
	return 0;
}

int cmp(const void *a,const void *b)
{
	int t,x1,y1,x2,y2;
	x1=*(int*)a,y1=*((int*)a+1),x2=*(int*)b,y2=*((int*)b+1);
	t=x1*y2-x2*y1;
	if(t>0)return -1;
	if(t<0)return 1;
	else if(x1*x1+y1*y1<x2*x2+y2*y2)return -1;
	else return 1;
	return 1;
}