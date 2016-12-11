#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int MAXN=100010,MAX_HASH=99991;
int s[MAXN][30],c[MAXN][30];
int count(int a,int b);
int k;
struct NODE
{
	struct NODE(){next=NULL;};
	int num;
	NODE *next;
}hash[MAX_HASH];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,a,n,sumc,max;
	while(~scanf("%d%d",&n,&k))
	{
		max=0;
		memset(s,0,sizeof(s));
		memset(hash,0,sizeof(hash));
		NODE *p=(NODE*)malloc(sizeof(NODE));
		hash[0].num=0,hash[0].next=p,p->next=NULL;

		for(i=1;i<=n;i++){
		    scanf("%d",&a);
			for(j=0,sumc=0;j<k;j++){
		     	s[i][j]=s[i-1][j]+((a&(1<<j))?1:0);	

				c[i][j]=s[i][j]-s[i][0];
				sumc+=c[i][j];
			}

			int t=sumc%MAX_HASH;
			if(t<0)t=-t;
			NODE *p=&hash[t];
			for(;p->next!=NULL;p=p->next){
				int ok=count(p->num,i);
				if(ok!=-1 && ok>max)max=ok;
			}	
			NODE *q=(NODE*)malloc(sizeof(NODE));
			p->num=i;
			p->next=q;
			q->next=NULL;
		}			
		printf("%d\n",max);
	}
	return 0;
}

int count(int a,int b)
{
	int j;
	for(j=0;j<k;j++){
		if(c[a][j]!=c[b][j])return -1;
	}
	return b-a;
}