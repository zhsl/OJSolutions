#include<stdio.h>
int stack[1000],chu[1000];
int main()
{
	int i,n,top,p,k,j,q,pri=-1;
	while(scanf("%d",&n)&&n!=0)
	{pri++;
	pri?printf("\n"):0;
		while(scanf("%d",&chu[0])&&chu[0]!=0)
		{
	    	top=p=0;
	    	for(i=1;i<n;)
		    	scanf("%d",&chu[i++]);
			for(i=1,k=1;i<=n;){
				for(;i<=n;){
					stack[top++]=i++;
					if(stack[top-1]==chu[p]){top--,p++;break;}
				}
				for(;top>=1&&stack[top-1]==chu[p];top--,p++);
				for(j=top-2,q=0;j>=0;)
					if(chu[p]==stack[j--]){k=0;break;}
				if(!k){break;}
			}
			printf("%s\n",k?"Yes":"No");
		}
	}
	return 0;
}