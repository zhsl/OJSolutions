#include<stdio.h>
int stack[1000],chu[1000];
int main()
{
	freopen("in.in","r",stdin);
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
				for(;top>1&&stack[top-1]==chu[p++];top--);
				for(j=top-2,q=0;j>=0;)
					if(chu[p]==stack[j--]){q=1;break;}
				if(q){k=0;break;}
			}
			printf("%s\n",k?"Yes":"No");
		}
	}
	return 0;
}