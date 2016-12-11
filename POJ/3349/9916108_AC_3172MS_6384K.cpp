#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
const int MAXN=100010,M_PRI=99991;
bool is_same(int *a,int *b);
int map[MAXN][6];
struct NODE
{
	NODE() {next=NULL;};
	int num;
	NODE *next;
}hash[M_PRI];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,n,sum,ok;
	while(~scanf("%d",&n))
	{
		ok=1;
		memset(hash,0,sizeof(hash));

		for(i=0;i<n;i++)
		{
			for(j=0,sum=0;j<6;j++){
				scanf("%d",&map[i][j]);
				sum+=map[i][j];
			}
			if(ok){
				sum%=M_PRI;
				NODE *p=&hash[sum];
				for(;p->next!=NULL;p=p->next){
					if( is_same(*(map+p->num),*(map+i)) )ok=0;
				}
				NODE *q=(NODE*)malloc(sizeof(NODE));
				p->num=i;
				p->next=q;
				q->next=NULL;
			}
		}
    	printf("%s\n",ok?"No two snowflakes are alike.":"Twin snowflakes found.");
	}
	return 0;
}

bool is_same(int *a,int *b)
{
	for(int i=0;i<6;i++){
		if( (a[i]==b[0] &&
			a[(1+i)%6]==b[1] &&
			a[(2+i)%6]==b[2] &&
			a[(3+i)%6]==b[3] &&
			a[(4+i)%6]==b[4] &&
			a[(5+i)%6]==b[5] )||
			(a[i]==b[5] &&
			a[(1+i)%6]==b[4] &&
			a[(2+i)%6]==b[3] &&
			a[(3+i)%6]==b[2] &&
			a[(4+i)%6]==b[1] &&
			a[(5+i)%6]==b[0] ) )return 1;
	}
	return 0;
}