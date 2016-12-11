#include<stdio.h>
const int MAXN=30;
int DFS(int x,int y,int tot);
char map[MAXN][MAXN];
int x1,y1,x2,y2,w,h,min,
dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while( scanf("%d%d",&w,&h) && w&&h )
	{
		min=0x7fffffff;

		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)x1=i,y1=j;
				else if(map[i][j]==3)x2=i,y2=j;
			}
		}

		DFS(x1,y1,0);

		printf("%d\n",min<=10?min:-1);
	}
	return 0;
}

int DFS(int x,int y,int tot)
{
	int i,nx,ny;
	for(i=0;i<4;i++){
		nx=x+dx[i],ny=y+dy[i];
		if(map[nx][ny]!=1 && nx>=0&&nx<h && ny>=0&&ny<w){  //判断方向
			if(tot+1>10)continue;
			do{                                                 //搜直线
				if(map[nx][ny]==3){if(tot+1<min)min=tot+1;return 1;}  //search succeed
				nx=nx+dx[i],ny=ny+dy[i];
			}while(map[nx][ny]!=1 && nx>=0&&nx<h && ny>=0&&ny<w);
		}
		else continue;  //nx,ny方向为block
		if(nx==h||nx<0 || ny==w||ny<0)continue; //出边界return 0;

		map[nx][ny]=0; //block变为vacant
		DFS(nx-dx[i],ny-dy[i],tot+1);
		map[nx][ny]=1;  //vacant变为block
	}
	return 0;  //error
}