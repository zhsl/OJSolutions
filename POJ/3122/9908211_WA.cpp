#include<stdio.h>
#include<math.h>
const double PI=acos(-1.0);
const int MAXN=10010;
int pie[MAXN];
int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,f,i,tot;
	double mid,high,low,v;
	scanf("%d",&t);
	while(t--)
	{
		low=0,high=-1;
		scanf("%d%d",&n,&f);
		f++;

		for(i=0;i<n;i++){
			scanf("%d",&pie[i]);
			if(pie[i]>high)high=pie[i];
		}

		for(high++,mid=(low+high)/2;high-low>1e-7 || tot<f;mid=(low+high)/2){
			for(i=0,tot=0;i<n;i++){
				tot+=(int)((pie[i]*pie[i])/(mid*mid));
			}
			tot<f?high=mid:low=mid;
			v=mid*mid*PI;
		}
		printf("%.4lf\n",v);
	}
	return 0;
}