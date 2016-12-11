#include<stdio.h>
#include<string.h>
const int MAXN=110;
int search();
char s1[MAXN],s2[MAXN],s12[MAXN+MAXN];
int tot,c,c12;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c);
		scanf("%s%s%s",s1,s2,s12);

		c12=2*c;
		tot=search();

		printf("%d %d\n",i,tot?tot:-1);
	}
	return 0;
}

int search()
{
	tot=0;
	int i,j,k;
	char s1t[MAXN],s2t[MAXN],s12t[MAXN+MAXN];
	strcpy(s1t,s1),strcpy(s2t,s2);
	while(1)
	{
     	for(i=0,j=0,k=0;k<c12;k++){
            if(k%2)s12t[k]=s1t[j++];
	    	else s12t[k]=s2t[i++];
		}
		s12t[k]='\0';
		tot++;
	    if(!strcmp(s12,s12t))return tot;  //succeed
		for(i=0;i<c;i++)
			s1t[i]=s12t[i];
		s1t[i]='\0';
		for(i=0;i<c;i++)
			s2t[i]=s12t[i+c];
		s2t[i]='\0';
		if(!strcmp(s1,s1t)&&(!strcmp(s2,s2t)))return 0;  //fail
	}
	return 0; //error
}