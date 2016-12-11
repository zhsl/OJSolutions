#include<stdio.h>
#include<string.h>
const int MAX=110,INF=100000;
int num[MAX][MAX],s[MAX];
int MAX_S(int *num_S);
int n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,ans,max,t;
	while(~scanf("%d",&n))
	{
		ans=-INF;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&num[i][j]);

		for(i=1;i<=n;i++){
			memset(s,0,sizeof(s));
			for(max=-INF,j=i;j<=n;j++){
				for(k=1;k<=n;k++)
					s[k]+=num[j][k];
				t=MAX_S(s);
				if(t>max)max=t;
			}
			if(max>ans)ans=max;
		}

		printf("%d\n",ans);
	}
	return 0;
}

int MAX_S(int *num_S)
{
	int max=-INF,i,min=INF,sum[MAX]={0};
	for(i=1;i<=n;i++)
		sum[i]+=sum[i-1]+num_S[i];
	for(i=1;i<=n;i++){
		if(sum[i-1]<min)
			min=sum[i-1];
		if(sum[i]-min>max)
			max=sum[i]-min;
	}
	return max;
}