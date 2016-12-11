#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
#define LL __int64
const int MAX=60,INF=200000000;
int T;
int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,c,d,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(d-c==c-b && c-b==b-a)
			ans=d+d-c;
		else ans=d*d/c;
		printf("%d %d %d %d %d\n",a,b,c,d,ans);
	}
	return 0;
}