#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
#define put(i) 
#define LL __int64
const int MAX=100000,INF=1000000000,MOD=2008;
int BFS(int x);
int print(int fa);
int q[MAX][5],vis[MAX];
int s;
char a[5];
int main()
{	
//	freopen("in.txt","r",stdin);
	int i,j,f;
	while(~scanf("%s",a))
	{
		memset(vis,0,sizeof(vis));
		for(i=s=0;i<4;i++){
			if(i)scanf("%s",a);
			for(j=0;j<4;j++){
				if(a[j]=='+')
					s|=( 1<<((i*4)+j) );
			}
		}

		vis[s]=1;
		f=BFS(s);

		printf("%d\n",q[f][1]);
		print(f);
	}
	return 0;
}

int BFS(int x)
{
	int i,j,k,front,rear,nx,d,fa;
	front=rear=0;
	q[rear][0]=x,q[rear][1]=0,q[rear++][2]=-1;
	while(front<rear)
	{
		x=q[front][0],d=q[front][1],fa=front++;
		if(!x)return front-1;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				nx=x;
				for(k=0;k<4;k++){
					if(k!=j)nx^=( 1<<((i*4)+k) );
					nx^=( 1<<((k*4)+j) );
				}
				if(!vis[nx]){
					vis[nx]=1;
					q[rear][0]=nx,q[rear][1]=d+1,q[rear][2]=fa;
					q[rear][3]=i,q[rear++][4]=j;
				}
			}
		}
	}
	return 0;
}

int print(int fa)
{
	if(!fa)return 1;
	print(q[fa][2]);
	printf("%d %d\n",q[fa][3]+1,q[fa][4]+1);
	return 0;
}