#include<stdio.h>
const int MAXN=1000;
int target[MAXN],stack[MAXN];
int main()
{
	//freopen("in.in","r",stdin);
	int A,B,i=-1,n,ok,top;
	while(scanf("%d",&n)&&n)
	{
		i!=-1?printf("\n"):0;
		while(scanf("%d",&target[0])&&target[0])
		{
			for(i=1;i<n;i++)
				scanf("%d",&target[i]);
			top=0,ok=1,A=1,B=0;
			while(B<n)
			{
				if(A==target[B])A++,B++;
				else if(top&&stack[top]==target[B])top--,B++;
				else if(A<=n)stack[++top]=A++;
				else {ok=0;break;}
			}
			printf("%s\n",ok?"Yes":"No");
		}
	}
	return 0;
}