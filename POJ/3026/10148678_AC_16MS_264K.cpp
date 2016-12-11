#include<stdio.h>
#include<string.h>
const int MAX1=60,MAX2=110,INF=1000;
int BFS();
int prim();
int d[MAX2],w[MAX2][MAX2],shine[MAX1][MAX1],q[MAX1*MAX1][2],
vis[MAX1][MAX1],n,m,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},K;
char map[MAX1][MAX1];
int main()
{
//	freopen("in.txt","r",stdin);
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		memset(d,0,sizeof(d));
		scanf("%d%d\n",&n,&m);
		for(i=0,K=0;i<m;i++){
			gets(map[i]);
			for(j=0;j<n;j++)
				if(map[i][j]=='A' || map[i][j]=='S')
					shine[i][j]=K++;
		}

		BFS();

		printf("%d\n",prim());
	}
	return 0;
}

int BFS()
{
	int i,j,k,front,rear,x,y,nx,ny,u,dis,sx,sy;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j]=='A' || map[i][j]=='S'){
				memset(vis,0,sizeof(vis));
				front=rear=0;
				sx=i,sy=j;
				vis[sx][sy]=1;	
				q[rear][0]=sx*n+sy;
				q[rear++][1]=0;
				w[ shine[i][j] ][ shine[i][j] ]=0;
				while(front<rear){
					u=q[front][0];
					x=u/n,y=u%n;
					dis=q[front++][1];
					for(k=0;k<4;k++){
						nx=x+dx[k],ny=y+dy[k];
						if(nx>=0&&nx<m && ny>=0&&ny<n
							&& map[nx][ny]!='#' && !vis[nx][ny]){
							vis[nx][ny]=1;
							u=nx*n+ny;
							q[rear][0]=u;
							q[rear++][1]=dis+1;
							if(map[nx][ny]=='A' || map[nx][ny]=='S')
								w[ shine[sx][sy] ][ shine[nx][ny] ]=dis+1;
						}
					}
				}
			}
		}
	}
	return 1;
}

int prim()
{
	int i,j,m,x,y,v[MAX2]={0},ans=0;
	for(i=0;i<K;i++)d[i]=INF;
	d[0]=0;
	for(i=0;i<K;i++){
		m=INF;
		for(j=0;j<K;j++)
			if(!v[j] && d[j]<m)m=d[x=j];
		v[x]=1;
		ans+=d[x];
		for(y=0;y<K;y++){
			if(w[y][x]<d[y] && w[x][y])d[y]=w[x][y];
		}
	}
	return ans;
}