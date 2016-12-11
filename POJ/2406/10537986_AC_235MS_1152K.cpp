#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL __int64
const int MAX=1000010,INF=60010;
int p[MAX];
char c[MAX];
int len;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,r,ok,ans;
	while(scanf("%s",c) && (c[0]!='.' || c[1]!='\0') )
	{
		len=strlen(c);
		for(r=0;r<len/2;r++){
			if(len%(r+1)==0){
				for(i=0,ok=1;i<len;i+=(r+1)){
					for(j=0;j<=r;j++)
						if(c[i+j]!=c[j]){ok=0;break;}
					if(!ok)break;
				}
				if(ok)break;
			}
		}
		if(ok)ans=len/(r+1);
		else ans=1;
		printf("%d\n",ans);
	}
	return 0;
}