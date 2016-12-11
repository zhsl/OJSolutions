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
int T,n;
int main()
{
//	freopen("in.txt","r",stdin);
	int cou5;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(n,cou5=0;n;cou5+=n/=5);
		printf("%d\n",cou5);
	}
	return 0;
}