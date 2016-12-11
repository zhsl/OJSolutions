#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
const int MAX=510,INF=200000010,MOD=7;
const double esp=1e-3,DNF=1e8;
int n,k;
int main()
{
//	freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&n,&k))
	{
		printf("%d\n",n&k==k?1:0);
	}
	return 0;
}