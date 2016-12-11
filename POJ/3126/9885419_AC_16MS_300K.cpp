#include<stdio.h>
#include<memory.h>
#include<queue>
const int MAXN=10010;
int BFS();
int num(int pr,int i);
int dis[MAXN],vis[MAXN],prime[MAXN],pr1,pr2,d[4]={1000,100,10,1};
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	memset(prime,0,sizeof(prime));
	for(int i=2;i<=110;i++){   //筛素数
		if(prime[i]==0)
	     	for(int j=i+i;j<MAXN;j+=i){
		    	prime[j]=1;
			}
	}

	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&pr1,&pr2);

		int ok=BFS();

		ok?printf("%d\n",dis[pr2]):printf("Impossible\n");
	}
	return 0;
}

int BFS()
{
	queue<int>q;
	q.push(pr1);
	vis[pr1]=1;
	int pr,npr,t,j;
	while(!q.empty())
	{
		pr=q.front();
		q.pop();
		if(pr==pr2)return 1; //search succeed;
		for(int i=0;i<4;i++){
			t=num(pr,i);
			for(j=0;j<10;j++){
				if(i==0&&j==0)continue;
				npr=pr+d[i]*(j-t);
				if(!prime[npr]&&(!vis[npr])){
					dis[npr]=dis[pr]+1;
					vis[npr]=1;
					q.push(npr);
				}
			}
		}
	}
	return 0;
}

int num(int pr,int i)
{
	int s;
	for(s=1;i<3;i++)
		s*=10;
	return (pr/s)%10;
}