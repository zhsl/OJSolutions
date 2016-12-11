#include<stdio.h>
#include<memory.h>
#include<string.h>
const int MAXN=10;
int DFS(int cur);
int sum(int *c);
char tnum[MAXN];
int n,num[MAXN],spa[MAXN],C[MAXN],tar,max,tot,line,ma;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,k;
	while(scanf("%d%s",&tar,tnum)&&tar)
	{
		memset(C,0,sizeof(C)),C[0]=1;
		tot=0,line=strlen(tnum);
		max=0x80000000;
		for(i=0;i<line;i++)  //转化为整形
			num[i]=tnum[i]-'0';
		for(i=line-1,k=1,n=0;i>=0;i--,k*=10)
			n+=num[i]*k;

		if(tar==n)printf("%d %d\n",tar,tar);
		else {
			DFS(1);
			if(tot>1)printf("rejected\n");
			else if(max==0x80000000)printf("error\n");
			else {
				printf("%d",max);
				for(i=ma;i>=0;i--)
					printf(" %d",spa[i]);
				putchar('\n');
			}
		}	
	}
	return 0;
}

int DFS(int cur)
{
	if(cur>line)return 1;  //search complied
	int s,i,j,t,k;

	s=sum(C);
	if(s==max)tot++;   //rejected
	if(s>max&&s<=tar){
		tot=0;
		max=s;
		for(i=line-1,j=0;i>=0;j++){
			for(t=C[i],k=1,spa[j]=0;C[i]==t;i--,k*=10)
				spa[j]+=num[i]*k;
		}
		ma=j-1;  //spa[]长度	
	}

	i=C[cur-1];
	C[cur]=i;
	DFS(cur+1);

	C[cur]=i+1;
	DFS(cur+1);
	C[cur]=0;

	return 1;  //all search complied
}

int sum(int *c)
{
	int i,k,s1,s2=0,t;
	for(i=line-1;i>=0;){
		for(s1=0,t=c[i],k=1;c[i]==t;i--,k*=10)
			s1+=k*num[i];
		s2+=s1;
	}
	return s2;
}