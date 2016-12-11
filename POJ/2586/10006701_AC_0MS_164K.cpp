#include<stdio.h>
int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,s,i,j,k,c[13];
	while(~scanf("%d%d",&a,&b))
	{
		for(i=0;i<12;i++)c[i]=a;
		for(i=0;i<=7;i++){
			while(1){
				for(j=i,s=0;j<i+5;j++)s+=c[j];

				if(s>0){
					for(k=i+4;c[k]!=a;k--);
					c[k]=-b;
				}
				else break;
			}
		}

		for(i=0,s=0;i<12;i++)s+=c[i];
		if(s<0)printf("Deficit\n");
		else printf("%d\n",s);
	}
	return 0;
}