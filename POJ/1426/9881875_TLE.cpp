#include<stdio.h>
#include<queue>
int BFS();
__int64 a;
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%I64d",&a)&&a)
	{
		BFS();
	}
	return 0;
}

int BFS()
{
	__int64 x;
	queue<__int64>q;
	q.push(1);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		if(x%a==0){printf("%I64d\n",x);return 1;}
		q.push(x*10+1);
		q.push(x*10);
	}
	return 0;
}