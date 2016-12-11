#include<stdio.h>
#include<string.h>
#define get(a,b) a&(1<<b)
#define put(a,b) a|=(1<<b)
#define out(a,b) a&=~(1<<b)
const int MAX=((1<<16)+10);
int BFS(int x);
int q[MAX][2],map,vis[MAX],d[5]={0,-4,1,4,-1};
int main()
{
//	freopen("in.txt","r",stdin);
	int i,min;
	char ch;
	memset(q,0,sizeof(q));
	memset(vis,0,sizeof(vis));
	map=0;
	for(i=0;i<16;i++){		
		scanf("%c",&ch);
		if(i==3 || i==7 || i==11 || i==15)getchar();
		if(ch=='b') map|=(1<<i);
	}
	/*
	for(i=0;i<16;i++)
		printf("%3d",get(map,i)?1:0);
	putchar('\n');
	*/

	min=BFS(map);

	if(min==-1)
		printf("Impossible\n");
	else 
		printf("%d\n",min);
	return 0;
}

int BFS(int map)
{
	int front,rear,i,j,nx,x,t,dd;
	front=rear=0;
	q[rear++][0]=map;
	vis[map]=1;
	while(front<rear)
	{
		x=q[front][0];
		dd=q[front++][1];
		if(x==65535 || x==0)return dd;
		for(i=0;i<16;i++){
			nx=x;
			for(j=0;j<5;j++){
				if( ((i==4||i==8)&&d[j]==-1) ||
					((i==7||i==11)&&d[j]==1) )continue;
				t=i+d[j];
				if(t>=0&&t<16){
					if(get(nx,t))out(nx,t);
					else put(nx,t);
				}
			}
			if(!vis[nx]){
				vis[nx]=1;
				q[rear][0]=nx;
				q[rear++][1]=dd+1;
			}
		}
	}
	return -1;
}