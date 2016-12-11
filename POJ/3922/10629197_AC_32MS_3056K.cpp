#include<stdio.h>
const int MAX=2000010;
int a[MAX];
int T,n,k;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t=1,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		a[0]=1;
		for(i=j=0;a[i]<n;i++){
			for(;a[j]*k<a[i];j++);
			a[i+1]=a[i]+a[j];
		}
		printf("Case %d: ",t++);
		if(a[i]==n)printf("lose\n");
		else {
			for(i--;i>=0;i--){
				if(n>=a[i])
					ans=a[i],n-=a[i];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}