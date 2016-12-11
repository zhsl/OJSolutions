#include<stdio.h>
#include<string.h>
const int MAXN=999991;
int hash(int s);
int num[MAXN],saves[MAXN],p[110];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,x1,x2,x3,x4,x5,a1,a2,a3,a4,a5,sum,t,ways;
	for(i=-50;i<0;i++)
		p[i+50]=i*i*i;
	for(i=1;i<=50;i++)
		p[i+49]=i*i*i;
	
	while(~scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5))
	{
		memset(num,0,sizeof(num));
		memset(saves,0,sizeof(saves));

		for(x1=0;x1<100;x1++)
			for(x2=0;x2<100;x2++)
				for(x3=0;x3<100;x3++){
					sum=a1*p[x1]+a2*p[x2]+a3*p[x3];
					t=hash(sum);
					num[t]++;
					saves[t]=sum;
				}

		ways=0;
		for(x4=0;x4<100;x4++)
			for(x5=0;x5<100;x5++){
				sum=-(a4*p[x4]+a5*p[x5]);
				t=hash(sum);
				ways+=num[t];
			}
		printf("%d\n",ways);
	}
	return 0;
}

int hash(int s)
{
	int t=s%MAXN;
	if(t<0)t+=MAXN;
	while(num[t]!=0 && saves[t]!=s)
		t=(t+3)%MAXN;
	return t;
}