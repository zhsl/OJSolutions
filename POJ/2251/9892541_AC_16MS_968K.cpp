#include<stdio.h>
#include<memory.h>
const int MAXN=40;
int BFS();
char map[MAXN][MAXN][MAXN],vis[MAXN][MAXN][MAXN];
int dis[MAXN][MAXN][MAXN],L,R,C,x1,y1,z1,x2,y2,z2;
int dx[6]={-1,0,1,0,0,0},dy[6]={0,1,0,-1,0,0},dz[6]={0,0,0,0,1,-1};
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,ok;
	while(scanf("%d%d%d",&L,&R,&C)&&L)
	{
		memset(vis,0,sizeof(vis));

		for(i=0;i<L;i++){
			for(j=0;j<R;j++){
				scanf("%s",map[i][j]);
			for(k=0;k<C;k++)
				if(map[i][j][k]=='S')z1=i,x1=j,y1=k;
				else if(map[i][j][k]=='E')z2=i,x2=j,y2=k;
			}
		}
		
		ok=BFS();

		ok?printf("Escaped in %d minute(s).\n",dis[z2][x2][y2]):printf("Trapped!\n");
	}
	return 0;
}

int BFS()
{
	int q[MAXN*MAXN*MAXN][2],front=0,rear=0,x,y,z,nx,ny,nz,u;
	q[rear][0]=x1*C+y1,q[rear++][1]=z1;
	vis[z1][x1][y1]=1;
	dis[z1][x1][y1]=0;
	while(front<rear)
	{
		u=q[front][0],z=q[front++][1];
		x=u/C,y=u%C;
		if(x==x2&&y==y2&&z==z2)return 1;
		for(int i=0;i<6;i++){
			nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
			if(nx>=0&&nx<R && ny>=0&&ny<C && nz>=0&&nz<L
				&& (map[nz][nx][ny]=='.'||map[nz][nx][ny]=='E') && (!vis[nz][nx][ny])){
				vis[nz][nx][ny]=1;
				dis[nz][nx][ny]=dis[z][x][y]+1;
				u=nx*C+ny;
				q[rear][0]=u,q[rear++][1]=nz;
			}
		}
	}
	return 0;
}