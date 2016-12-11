#include<stdio.h>
const int MAXN=100010;
int judge(int mid);
int mon[MAXN],N,M;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,low,mid,high,tot;
	while(~scanf("%d%d",&N,&M))
	{
    	low=0x80000000;
		for(i=0,high=1;i<N;i++){
			scanf("%d",&mon[i]);
			high+=mon[i];
			if(mon[i]>low)low=mon[i];
		}
		while(high-low!=1){
			mid=(low+high)/2;
			tot=judge(mid);
			if(tot>M)low=mid;
			else high=mid;
		}
		mid=judge(low)<=M?low:high;
		printf("%d\n",mid);
	}
	return 0;
}

int judge(int mid)
{
	int i,tot,s,count;
	for(i=0,tot=0;i<N;count==1?i++:0){
		for(s=0,count=0;i<N;i++){
			s+=mon[i];
			count++;
			if(s>mid)break;
		}
		tot++;
	}
	return tot;
}