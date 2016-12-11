#include<stdio.h>
#include<string.h>
int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,i;
	char c[65],ans[65];
	__int64 y;
	unsigned __int64 x;
	scanf("%d",&t);
	while(t--)
	{
		memset(ans,'\0',sizeof(ans));
		scanf("%d%s%I64d",&n,c,&y);
		x=y;
		if(y<0){
			x=-x;
			for(i=0;i<n;i++)
				c[i]=c[i]=='p'?'n':'p';
		}

		for(i=n-1;i>=0;i--){
			if(x&1){
				ans[i]='1';
				if(c[i]=='n')x+=1;
				x>>=1;
			}
			else {
				ans[i]='0';
				x>>=1;
			}
		}
		if(x)printf("Impossible");
		else printf("%s",ans);
		putchar('\n');
	}
	return 0;
}