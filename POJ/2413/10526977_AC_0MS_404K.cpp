#include<stdio.h>
#include<string.h>
const int MAX=110;
struct FI
{
	int a[MAX];
	int len;
}f[MAX*5],num1,num2;
int cmp(int i,int *b);
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t,ans;
	char c1[MAX],c2[MAX];
	memset(f,0,sizeof(f));
	f[0].a[0]=1,f[0].len=1;
	f[1].a[0]=1,f[1].len=1;
	for(i=2;f[i-1].len<102;i++){
		for(j=t=0;j<f[i-1].len;j++){
			f[i].a[j]=f[i-1].a[j]+f[i-2].a[j]+t;
			t=f[i].a[j]/10;
			f[i].a[j]%=10;
		}
		if(t)f[i].a[j]=t,f[i].len=f[i-1].len+1;
		else f[i].len=f[i-1].len;
	}

	while(~scanf("%s%s",c1,c2))
	{
		ans=0;
		memset(num1.a,0,sizeof(num1.a));
		memset(num2.a,0,sizeof(num2.a));
		num1.len=strlen(c1);
		num2.len=strlen(c2);
		
		for(i=0;i<num1.len;i++)
			num1.a[i]=c1[num1.len-i-1]-'0';
		for(i=0;i<num2.len;i++)
			num2.a[i]=c2[num2.len-i-1]-'0';
		if(num1.len==1 && !num1.a[0] && num2.len==1 && !num2.a[0])break;
		for(i=1;f[i].len<num1.len;i++);
		for(i=1;f[i].len<=num2.len;i++)
			if(cmp(i,num1.a)>=0 && cmp(i,num2.a)<=0)ans++;
			
		printf("%d\n",ans);
	}
	return 0;
}

int cmp(int i,int *b)
{
	int j;
	for(j=MAX-1;j>=0;j--){
		if(f[i].a[j]>b[j])return 1;
		else if(f[i].a[j]<b[j])return -1;
	}
	return 0;
}