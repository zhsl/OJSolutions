#include<stdio.h>
#include<string.h>
const int MAX=110;
int dp(int x,int y);
int map[MAX][MAX],d[MAX][MAX],r,c,dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,ans,t;
	while(~scanf("%d%d",&r,&c))
	{
		ans=0x80000000;
		memset(d,0,sizeof(d));
		for(i=0;i<r;i++){
			for(j=0;j<c;j++)
				scanf("%d",&map[i][j]);
		}

		for(i=0;i<r;i++)
			for(j=0;j<c;j++){
				t=dp(i,j);
				if(t>ans)ans=t;
			}

		printf("%d\n",ans);
	}
	return 0;
}

int dp(int x,int y)
{
	int k,nx,ny,t;
	int& ans=d[x][y];
	if(ans)return ans;
	ans=1;
	for(k=0;k<4;k++){
		nx=x+dx[k],ny=y+dy[k];
		if(nx>=0&&nx<r && ny>=0&&ny<c && map[x][y]<map[nx][ny]){
			t=dp(nx,ny)+1;
	    	if(t>ans)ans=t;
		}
	}
	return ans;
}