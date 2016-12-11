#include<stdio.h>
#include<stdlib.h>
const int MAX=50010;
int cmp_num(const void *a,const void *b);
int d[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int L,N,M,i,low,mid,high,tot,a,b;
	while(~scanf("%d%d%d",&L,&N,&M))
	{
        low=-1,high=L+1,mid=L;
		for(i=0;i<N;i++)
			scanf("%d",&d[i]);
		
		qsort(d,N,sizeof(int),cmp_num);

		if(N && N>M)
			for(mid=(low+high)/2;high-low!=1;mid=(low+high)/2){
				for(i=0,a=0,b=d[0],tot=0;i<N;a=b,b=d[++i]){
					while(b-a<mid && i<N){
						tot++;
						b=d[++i];
					}
					if(i==N-1){if(L-d[N-1]<mid)tot++; break;}
					if(i==N){if(L-a<mid)tot++; break;}
				}
       
	           	if(tot<=M)low=mid;
	        	else high=mid;
			}
		printf("%d\n",mid);
	}
	return 0;
}

int cmp_num(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}