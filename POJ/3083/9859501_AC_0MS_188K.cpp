#include<stdio.h>
#include<memory.h>
const int MAXN=50;
int L_DFS();
int R_DFS();
int S_BFS();
int w,h,x1,y1,x2,y2,q[MAXN*MAXN],fa[MAXN][MAXN]
,dlx[4]={0,-1,0,1},dly[4]={-1,0,1,0}
,drx[4]={0,-1,0,1},dry[4]={1,0,-1,0};
char map[MAXN][MAXN],vis[MAXN][MAXN]={{0}};
int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&w,&h);
		for(i=0;i<h;i++){
			scanf("%s",map[i]);
			for(j=0;j<w;j++)
				if(map[i][j]=='S')x1=i,y1=j;
				else if(map[i][j]=='E')x2=i,y2=j;
		}

		printf("%d %d %d\n",L_DFS(),R_DFS(),S_BFS());
	}
	return 0;
}

int L_DFS()
{
	int i,j,x,y,nx,ny,tot;
	for(i=0;i<4;i++){ //寻找起点出口
		nx=x1+dlx[i],ny=y1+dly[i];
		if(nx>=0&&nx<h && ny>=0&&ny<w
			&& map[nx][ny]=='.'){vis[nx][ny]=(i+3)%4;break;}
	}

	for(x=nx,y=ny,tot=2;x!=x2||y!=y2;){  //深度搜索
		for(i=vis[x][y],j=0;j<4;j++,i=(i+1)%4){
			nx=x+dlx[i],ny=y+dly[i];
			if(map[nx][ny]=='.'||map[nx][ny]=='E'){
				vis[nx][ny]=(i+3)%4;
				x=nx,y=ny;
				tot++;
				break;
			}
		}
	}
	return tot;
}

int R_DFS()
{
	int i,j,x,y,nx,ny,tot;
	for(i=0;i<4;i++){ //寻找起点出口
		nx=x1+drx[i],ny=y1+dry[i];
		if(nx>=0&&nx<h && ny>=0&&ny<w
			&& map[nx][ny]=='.'){vis[nx][ny]=(i+3)%4;break;}
	}

	for(x=nx,y=ny,tot=2;x!=x2||y!=y2;){  //深度搜索
		for(i=vis[x][y],j=0;j<4;j++,i=(i+1)%4){
			nx=x+drx[i],ny=y+dry[i];
			if(map[nx][ny]=='.'||map[nx][ny]=='E'){
				vis[nx][ny]=(i+3)%4;
				x=nx,y=ny;
				tot++;
				break;
			}
		}
	}
	return tot;
}

int S_BFS()
{
	memset(vis,0,sizeof(vis));
	memset(fa,0,sizeof(fa));
	int i,u,x,y,nx,ny,tot,front=0,rear=0;
	q[rear++]=x1*w+y1;
	vis[x1][y1]=1;
	while(front<rear)
	{
		u=q[front++];
		x=u/w,y=u%w;
		if(x==x2&&y==y2)break;
		for(i=0;i<4;i++){
			nx=x+dlx[i],ny=y+dly[i];
			if(nx>=0&&nx<h && ny>=0&&ny<w && !vis[nx][ny] && (map[nx][ny]=='.'||map[nx][ny]=='E')){
				vis[nx][ny]=1;
				q[rear++]=nx*w+ny;
				fa[nx][ny]=x*w+y;
			}
		}
	}
	for(nx=x2,ny=y2,tot=1;nx!=x1||ny!=y1;tot++){
		x=fa[nx][ny]/w;
		ny=fa[nx][ny]%w;
		nx=x;
	}
	return tot;
}