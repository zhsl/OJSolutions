#include<stdio.h>
const int MAXN=110;
int a[MAXN][MAXN],d[MAXN][MAXN],n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				scanf("%d",&a[i][j]);
		
		for(t=n-1,i=0;i<n;i++)d[t][i]=a[t][i];
		for(i=n-1;i>=0;i--)
			for(j=0;j<=i;j++)
				d[i][j]=a[i][j]+( d[i+1][j]>d[i+1][j+1]?d[i+1][j]:d[i+1][j+1] );

		printf("%d\n",d[0][0]);
	}
	return 0;
}