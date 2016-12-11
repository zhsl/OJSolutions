#include<stdio.h>
#include<string.h>
const int MAX=1000010;
char c[MAX];
__int64 dx[10]={-2,1,0,-1,1,-2,-1,1,0,-1},
dy[10]={-2,-1,-1,-1,0,-2,0,1,1,1};
int main()
{
//	freopen("in.txt","r",stdin);
	__int64 n,i,x1,y1,x2,y2,k,s;
	scanf("%I64d",&n);
	while(n--)
	{
		scanf("%s",c);
		x1=y1=x2=y2=0;
		s=0;
		for(i=0;c[i]!=53;i++){
			k=c[i]-48;
			x2=x1+dx[k];
			y2=y1+dy[k];
			s+=x1*y2-x2*y1;
			x1=x2,y1=y2;
		}
		if(s<0)s=-s;
		if(s&1)printf("%I64d.5\n",s/2);
		else printf("%I64d\n",s/2);
	}
	return 0;
}