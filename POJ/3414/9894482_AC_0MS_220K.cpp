#include<stdio.h>
#include<memory.h>
const int MAXN=110;
int BFS();
void print(int fa);
int vis[MAXN][MAXN],q[MAXN*MAXN*MAXN][5];
int A,B,C,fa;
int main()
{	
//	freopen("in.txt","r",stdin);
	int ok;
	while(scanf("%d%d%d",&A,&B,&C)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		
		ok=BFS();

		if(ok){
			printf("%d\n",q[fa][4]);print(fa);
		}
		else printf("impossible\n");
	}
	return 0;
}

int BFS()
{
	int front=0,rear=0,a,b,na,nb,nfront,tot;
	q[rear][0]=0,q[rear][1]=0,q[rear][2]=0,q[rear++][4]=0;
	vis[0][0]=1;
	while(front<rear)
	{
		a=q[front][0],b=q[front][1],tot=q[front][4];
		nfront=front,front++;
		if(a==C||b==C){//search succeed
			fa=nfront;
			return 1;
		}
		
		na=A,nb=b;
		if(!vis[na][nb]){
			vis[na][nb]=1;
			q[rear][0]=na,q[rear][1]=nb;
			q[rear][2]=1,q[rear][3]=nfront;
			q[rear++][4]=tot+1;
		}		
		na=a,nb=B;
		if(!vis[na][nb]){
			vis[na][nb]=1;
			q[rear][0]=na,q[rear][1]=nb;
			q[rear][2]=2,q[rear][3]=nfront;
			q[rear++][4]=tot+1;
		}
		na=0,nb=b;
		if(!vis[na][nb]){  //only i or j
			vis[na][nb]=1;
			q[rear][0]=na,q[rear][1]=nb;
			q[rear][2]=3,q[rear][3]=nfront;
			q[rear++][4]=tot+1;
		}
		na=a,nb=0;
		if(!vis[na][nb]){
			vis[na][nb]=1;
			q[rear][0]=na,q[rear][1]=nb;
			q[rear][2]=4,q[rear][3]=nfront;
			q[rear++][4]=tot+1;
		}

		int is_full;   //i,j
		is_full=(a+b)/B;
		is_full?(na=a+b-B,nb=B):(na=0,nb=a+b);
		if(!vis[na][nb]){
			vis[na][nb]=1;
			q[rear][0]=na,q[rear][1]=nb;
			q[rear][2]=5,q[rear][3]=nfront;
			q[rear++][4]=tot+1;
		}
		is_full=(a+b)/A;
		is_full?(na=A,nb=a+b-A):(na=a+b,nb=0);
		if(!vis[na][nb]){
			vis[na][nb]=1;
			q[rear][0]=na,q[rear][1]=nb;
			q[rear][2]=6,q[rear][3]=nfront;
			q[rear++][4]=tot+1;
		}
	}
	return 0;
}

void print(int fa)
{
	if(fa==0)return;
	print(q[fa][3]);
	if(q[fa][2]<=2)printf("FILL(%d)\n",q[fa][2]);
	else if(q[fa][2]<=4)printf("DROP(%d)\n",q[fa][2]/2);
	else {
		if(q[fa][2]==5)printf("POUR(1,2)\n");
		else printf("POUR(2,1)\n");
	}
	return;
}