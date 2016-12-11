#include<stdio.h>
void print_direct(int i,int j);
const int MAXN=5,N=5;
int mat[MAXN][MAXN],vis[MAXN][MAXN],fa[MAXN][MAXN];
int main()
{
	//freopen("in.in","r",stdin);
	int i,j,x,y;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&mat[i][j]);
	int queue[MAXN*MAXN][2]={{0,0}},front=0,rear=1,
		dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	vis[0][0]=1;
	//BFS
	while(front<=rear)
	{
		x=queue[front][0],y=queue[front++][1];	
		for(i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(mat[nx][ny]==0&&(nx>=0&&nx<N&&ny>=0&&ny<N)&&vis[nx][ny]==0)
				queue[rear][0]=nx,
				queue[rear++][1]=ny,
				vis[nx][ny]=1,
				fa[nx][ny]=x*N+y;
		}
	}
	//print
	print_direct(N-1,N-1);
	printf("(%d, %d)\n",N-1,N-1);
	return 0;
}
void print_direct(int i,int j)
{
	if(i==0&&j==0)return;
	print_direct(fa[i][j]/N,fa[i][j]%N);
	printf("(%d, %d)\n",fa[i][j]/N,fa[i][j]%N);
}