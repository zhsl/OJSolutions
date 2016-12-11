#include<stdio.h>
#include<memory.h>
const int MAXN=36;
int search();
int is_ok(int line,int tar);
char map[MAXN][MAXN];
int vis[MAXN][MAXN],n,min;
int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		min=0x80000000;
		memset(vis,0,sizeof(vis));

		for(int i=0;i<n;i++){
			scanf("%s",map[i]);
			for(int j=0;map[i][j]!='\0';j++)
				if(map[i][j]!=':')vis[i][map[i][j]-'A']=1;
		}

    	search();

     	printf("%d ",min);
		printf("%s needed.\n",min==1?"channel":"channels");
	}
	return 0;
}

int search()
{
	for(int i=0;i<n;i++){
		for(int j=1;is_ok(i,j);j++);
		if(j>min)min=j;    //是否为最小值
		for(int k=0;k<n;k++)    //标记
			if(vis[k][i])vis[k][i]=j;
	}
	return 1;
}

int is_ok(int line,int tar)
{
	for(int i=0;i<line;i++){
		if(vis[i][line]){
			if(line==i)
				for(int j=0;j<line;j++){
					if(vis[i][j]==tar)return 1;
				}
			else {
				if(vis[i][i]==tar)return 1;
			}
		}
	}
	return 0; //可以
}