#include<stdio.h>
#include<memory.h>
int DFS(int b,int cur);
int judge(int x,int y,int num);
const int MAXN=10;
char map[MAXN][MAXN];
int map_zero[MAXN*MAXN][2],vis_x[MAXN][MAXN],vis_y[MAXN][MAXN],b;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,n,tot,t,c;
	scanf("%d",&n);
	while(n--)
	{
		tot=0,c=0;
		memset(vis_x,0,sizeof(vis_x));
		memset(vis_y,0,sizeof(vis_y));

		for(i=0;i<9;i++){
			scanf("%s",map[i]);
			for(j=0;j<9;j++)
				if(map[i][j]!='0'){
					tot++;
					t=map[i][j]-'1';
					vis_x[i][t]=1;
					vis_y[j][t]=1;
				}
				else {
					map_zero[c][0]=i;
					map_zero[c][1]=j;
					c++;
				}
		}	

		if(DFS(0,tot))
			for(i=0;i<9;i++)
		    	printf("%s\n",map[i]);
	}
	return 0;
}

int DFS(int b,int cur)
{
	if(cur==81)return 1;
	int x=map_zero[b][0],y=map_zero[b][1];
	for(int j=0;j<9;j++)
	{
		if(!vis_x[x][j] && (!vis_y[y][j]) && judge(x,y,j)){
			map[x][y]=j+'1';
			vis_x[x][j]=vis_y[y][j]=1;
			if(DFS(b+1,cur+1))return 1;
			map[x][y]='0';
			vis_x[x][j]=vis_y[y][j]=0;
		}
	}
	return 0;
}

int judge(int x,int y,int a)
{
	int i,j;
	for(i=x/3*3;i<=x/3*3+2;i++)
		for(j=y/3*3;j<=y/3*3+2;j++)
			if(map[i][j]=='1'+a)return 0;
	return 1;
}