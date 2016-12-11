#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
#define LL __int64
const int MAX=1050000,INF=1000000000,MOD=2008;
int n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,cou;
	while(~scanf("%d",&n) && n)
	{
		for(i=cou=0;i<31;i++){
			if( n&(1<<i) && !(n&(1<<(i+1))) ){
				n^=(1<<i);
				n^=(1<<(i+1));
				break;
			}
			if( n&(1<<i) )cou++,n^=(1<<i);
		}
		for(i=0;i<cou;i++)
			n|=(1<<i);
		printf("%d\n",n);
	}
	return 0;
}