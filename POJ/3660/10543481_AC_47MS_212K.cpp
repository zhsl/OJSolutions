#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define LL __int64
const int MAX=110;
int num[MAX][MAX];
int n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,a,b,ans;
	while(~scanf("%d%d",&n,&m))
	{
		memset(num,0,sizeof(num));
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			num[a-1][b-1]=1;
		}

		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(num[i][k] && num[k][j])
						num[i][j]=1;

		for(i=ans=0;i<n;i++){
			for(j=k=0;j<n;j++)
				if(num[i][j] || num[j][i])k++;
			if(k==n-1)ans++;
		}

		printf("%d\n",ans);
	}
	return 0;
}