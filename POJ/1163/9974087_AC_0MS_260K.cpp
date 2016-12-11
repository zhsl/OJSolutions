#include<stdio.h>
#include<string.h>
const int MAXN=110;
int DP(int i,int j);
int a[MAXN][MAXN],d[MAXN][MAXN],n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d",&n))
	{
		memset(d,-1,sizeof(d));
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				scanf("%d",&a[i][j]);

    	DP(0,0);			

		printf("%d\n",d[0][0]);
	}
	return 0;
}

int DP(int i,int j)
{
	if(d[i][j]>=0)return d[i][j];
	int l=DP(i+1,j),r=DP(i+1,j+1);
	d[i][j]=a[i][j]+( i+1==n?0:(l>r?l:r) );
	return d[i][j];
}