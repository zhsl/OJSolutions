#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=1010,INF=0x7fffffff,MOD=2009;
const double esp=1e-8,DNF=100000;
int main()
{
//	freopen("in.txt","r",stdin);
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		printf("%d\n",a%b);
	}
    return 0;
}