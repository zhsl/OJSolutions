#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const int MAX=100100,INF=100000010;
int BFS(int x);
int q[MAX][2],vis[MAX],w[4][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
int a;
char s[5][5];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,ans;
	while(~scanf("%s",s[0]))
	{
		a=0;
		memset(vis,0,sizeof(vis));
		for(i=0;i<4;i++){
			if(i)scanf("%s",s[i]);
			for(j=0;j<4;j++)
				if(s[i][j]=='b')a|=(1<<w[i][j]);
		}

		ans=BFS(a);

		if(ans!=-1)printf("%d\n",ans);
		else printf("Impossible\n");
	}
	return 0;
}

int BFS(int x)
{
	int i,j,front=0,rear=0,d,nx;
	q[rear][0]=x,q[rear++][1]=0;
	vis[x]=1;
	while(front<rear)
	{
		x=q[front][0],d=q[front++][1];
		if(!x || x==65535)return d;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				nx=x;
				nx^=(1<<w[i][j]);
				if(i>0)nx^=(1<<w[i-1][j]);
				if(i<3)nx^=(1<<w[i+1][j]);
				if(j>0)nx^=(1<<w[i][j-1]);
				if(j<3)nx^=(1<<w[i][j+1]);
				if(!vis[nx]){
					vis[nx]=1;
					q[rear][0]=nx;
					q[rear++][1]=d+1;
				}
			}
		}
	}
	return -1;
}