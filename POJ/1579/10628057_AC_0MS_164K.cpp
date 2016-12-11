#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const int MAX=150,INF=100000010;
int DFS(int a,int b,int c);
int a,b,c;
int w[22][22][22];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d%d",&a,&b,&c) && (a!=-1 || b!=-1 || c!=-1) )
	{
		memset(w,0,sizeof(w));
		printf("w(%d, %d, %d) = %d\n",a,b,c,DFS(a,b,c));
	}
	return 0;
}

int DFS(int a,int b,int c)
{
	if(a<=0 || b<=0 || c<=0)return 1;
	if(a>20 || b>20 || c>20)return 1048576;
	if(a<b && b<c){
		if(w[a][b][c])return w[a][b][c];
		return w[a][b][c]=DFS(a,b,c-1)+DFS(a,b-1,c-1)-DFS(a,b-1,c);
	}
	else {
		if(w[a][b][c])return w[a][b][c];
		return w[a][b][c]=DFS(a-1,b,c)+DFS(a-1,b-1,c)+DFS(a-1,b,c-1)-DFS(a-1,b-1,c-1);
	}
}