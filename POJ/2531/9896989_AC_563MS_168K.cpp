#include<stdio.h>
const int MAXN=30;
int DFS(int cur);
int sum(int c);
int map[MAXN][MAXN],C,max,N;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d",&N)!=EOF)
	{
		C=0;
		max=0x80000000;

		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				scanf("%d",&map[i][j]);
		}

		DFS(0);

		printf("%d\n",max);
	}
	return 0;
}

int DFS(int cur)
{
	if(cur>N)return 1;  //search complete
	if(C&(1<<(cur-1))){
     	int t;
    	t=sum(C);
     	max=t>max?t:max;
	}

	C|=(1<<cur);
	DFS(cur+1);
	C&=~(1<<cur);
	DFS(cur+1);

	return 0; //error
}

int sum(int c)
{
	int i,j,ma=0,mb=0,tot=0,A[MAXN],B[MAXN];
	for(i=0;i<N;i++)
		c&(1<<i)?A[ma++]=i:B[mb++]=i;
	for(i=0;i<ma;i++){
		for(j=0;j<mb;j++)
			tot+=map[A[i]][B[j]];
	}
	return tot;
}