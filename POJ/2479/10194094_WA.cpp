#include<stdio.h>
const int MAX=50010,INF=500000010;
int THE_MAX1(int *s,int *a);
int THE_MAX2(int *s,int *a);
int num[MAX],s1[MAX],s2[MAX],max1[MAX],max2[MAX],n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,T,ans,t;
	scanf("%d",&T);
	while(T--)
	{
		ans=-INF;
		scanf("%d",&n);
		s1[0]=s2[0]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&num[i]);
			s1[i]=s1[i-1]+num[i];
		}
		for(i=1,j=n;j>=0;i++,j--)
			s2[i]=s2[i-1]+num[j];

		THE_MAX1(s1,max1);
		THE_MAX2(s2,max2);

		for(i=1;i<=n;i++){
			t=max1[i]+max2[n-i+1];
			if(t>ans)ans=t;
		}

		printf("%d\n",ans);
	}
	return 0;
}

int THE_MAX1(int *s,int *a)
{
	a[1]=0;
	int i,max=-INF,mins=INF;
	for(i=1;i<=n;i++){
		if(s[i-1]<mins)
			mins=s[i-1];
		if(s[i]-mins>max)
			max=s[i]-mins;
		a[i+1]=max;
	}
	return 1;
}


int THE_MAX2(int *s,int *a)
{
	int i,max=-INF,mins=INF;
	for(i=1;i<=n;i++){
		if(s[i-1]<mins)
			mins=s[i-1];
		if(s[i]-mins>max)
			max=s[i]-mins;
		a[i]=max;
	}
	return 1;
}