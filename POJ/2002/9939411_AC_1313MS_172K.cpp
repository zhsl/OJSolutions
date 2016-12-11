#include<stdio.h>
#include<stdlib.h>
const int MAXN=1010;
int cmp_num(const void *a,const void *b);
void judge(int x1,int y1,int x2,int y2);
int map[MAXN][2],tot,n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&map[i][0],&map[i][1]);

		qsort(map,n,sizeof(int)*2,cmp_num);

		tot=0;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++){
				judge(map[i][0],map[i][1],map[j][0],map[j][1]);
			}
		
		printf("%d\n",tot/2);
	}
	return 0;
}
void judge(int x1,int y1,int x2,int y2)
{
	int t,i,x3,y3,x4,y4,ok,low,mid,high;
	if(y1>y2)t=x1,x1=x2,x2=t,t=y1,y1=y2,y2=t;
	x3=x1+(y1-y2);y3=y1-(x1-x2);
    x4=x2+(y1-y2);y4=y2-(x1-x2);
	ok=0,low=0,high=n;	
	while(low<high){
		mid=(low+high)/2;
		if(map[mid][0]>=x3)high=mid;
		else low=mid+1;
	}
	for(i=low;map[i][0]==x3;i++)
		if(map[i][1]==y3){ok=1;break;}

    if(ok){
		ok=0,low=0,high=n;
		while(low<high){
	    	mid=(low+high)/2;
			if(map[mid][0]>=x4)high=mid;
			else low=mid+1;
		}
		for(i=low;map[i][0]==x4;i++)
			if(map[i][1]==y4){ok=1;break;}
	}
	if(ok){
		tot++;
	}
}

int cmp_num(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}