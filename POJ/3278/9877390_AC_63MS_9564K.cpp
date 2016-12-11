//STATUS:C++_AC_
#include<stdio.h>
#include<memory.h>
int BFS();
const int MAXN=1100100;
int vis[200010],n,k,q[MAXN][2],d[2]={1,-1};
int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(q,0,sizeof(q));
		memset(vis,0,sizeof(vis));
		
		k<=n?printf("%d\n",n-k):printf("%d\n",BFS());
	}
	return 0;
}

int BFS()
{
	int i,front=0,rear=0,n1,n2,t;
	q[rear++][0]=n;
	vis[n]=1;
	while(front<rear)
	{
		n1=q[front][0];
		if(n1==k)return q[front][1];
		t=q[front++][1]+1;
		for(i=0;i<2;i++){
			n2=n1+d[i];
			if(!vis[n2]){
		    	vis[n2]=1;  //vis
		    	q[rear][0]=n2;
		     	q[rear++][1]=t;
			}
		}
		if( k-n1>2*n1-k ){
			n2=2*n1;
			if(!vis[n2]){
				vis[n2]=1;  //vis
		    	q[rear][0]=n2;
				q[rear++][1]=t;
			}
		}
	}
	return 0;
}