#include<stdio.h>
const int MAXN=1010;
int d1[MAXN],d2[MAXN];
double num[MAXN];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,max,s,t;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
			scanf("%lf",&num[i]);

		for(i=1,d1[0]=1;i<n;i++)
			for(j=i-1,d1[i]=1;j>=0;j--)
				if(num[i]>num[j] && d1[j]+1>d1[i])d1[i]=d1[j]+1;
		max=d1[n-1]+1;
		for(i=n-2,d2[n-1]=1;i>=0;i--){
			for(j=i+1,d2[i]=1;j<n;j++)
				if(num[i]>num[j] && d2[j]+1>d2[i])d2[i]=d2[j]+1;
			s=d1[i]+d2[i];
			if(s>max)max=s;
		}
		for(i=0,t=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(num[i]==num[j] && d1[i]+d2[j]>t)t=d1[i]+d2[j];
		max--;
		if(t>max)max=t;
		printf("%d\n",n-max);
	}
	return 0;
}