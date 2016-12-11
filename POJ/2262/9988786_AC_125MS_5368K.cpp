#include<stdio.h>
const int MAX=1000010;
int prime[78500],w[MAX];
bool p[MAX]={0};
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,c,n,a,b,ok;
	for(i=2,c=0;i<MAX;i++)if(!p[i]){
		prime[c]=i,w[i]=c++;
		for(j=i+i;j<MAX;j+=i)
			p[j]=1;
	}

	while(~scanf("%d",&n) && n)
	{
		ok=0;
		for(i=n-3;i>0;i--)if(!p[i])break;
		for(i=w[i];i>0 && b>=a;i--){
			b=prime[i];
			a=n-b;
			if(!p[a]){ok=1;break;}
		}
		if(ok)printf("%d = %d + %d\n",n,a,b);
		else printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}