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
	int t,cou2,cou5;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(t=n,cou2=0;t;cou2+=t/=2);
		for(t=n,cou5=0;t;cou5+=t/=5);
		printf("%d\n",cou2<cou5?cou2:cou5);
	}
	return 0;
}