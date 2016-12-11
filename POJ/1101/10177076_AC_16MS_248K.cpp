#include<stdio.h>
#include<string.h>
const int MAX=80;
int BFS(int x,int y);
int w,h,vis[MAX][MAX],q[MAX*MAX][2],d[MAX][MAX],
dx[4]={0,-1,0,1},dy[4]={-1,0,1,0},
x1,y1,x2,y2;
char map[MAX][MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,k1,k2,j;
	for(k1=1;scanf("%d%d",&w,&h) && w&&h;k1++)
	{
		getchar();
		printf("Board #%d:\n",k1);
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				scanf("%c",&map[i][j]);
			}
			map[i][j+1]='\0';
			getchar();
		}
		for(i=0;i<=h;i++)
			map[i][0]=map[i][w+1]=' ';
		for(j=0;j<=w;j++)
			map[0][j]=map[h+1][j]=' ';

		for(k2=1;scanf("%d%d%d%d",&y1,&x1,&y2,&x2) && 
			x1&&y1&&x2&&y2;k2++){
			memset(vis,0,sizeof(vis));
			memset(d,0,sizeof(d));

			BFS(x1,y1);

			printf("Pair %d: ",k2);
			if(vis[x2][y2])
				printf("%d segments.\n",d[x2][y2]);
			else printf("impossible.\n");		
		}
		putchar('\n');
	}
	return 0;
}

int BFS(int x,int y)
{
	int front,rear,nx,ny,i;
	front=rear=0;
	q[rear][0]=x,q[rear++][1]=y;
	vis[x][y]=1;
	while(front<rear)
	{
		x=q[front][0],y=q[front++][1];
		for(i=0;i<4;i++){
			nx=x+dx[i];
			ny=y+dy[i];
			for(;(map[nx][ny]!='X' || nx==x2&&ny==y2) && nx>=0&&nx<=h+1 && ny>=0&&ny<=w+1;){
				if(!vis[nx][ny]){
					vis[nx][ny]=1;
					d[nx][ny]=d[x][y]+1;
					q[rear][0]=nx,q[rear++][1]=ny;
				}
				else if(vis[nx][ny] && d[x][y]<d[nx][ny]){
					d[nx][ny]=d[x][y]+1;
					q[rear][0]=nx,q[rear++][1]=ny;
				}
				nx+=dx[i];
 	     		ny+=dy[i];
			}
		}
	}
	return 1;
}
