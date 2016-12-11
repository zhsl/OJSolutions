#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
#define LL __int64
const int MAX=110,INF=200000000;
void gcd(LL a,LL b,LL& d,LL& x,LL& y){
	if(!b){d=a;x=1;y=0;}
	else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
LL A,B,C,K,x,y,d,a,b,c;
int main()
{
//	freopen("in.txt","r",stdin);
	LL bt;
	while(~scanf("%I64d%I64d%I64d%I64d",&A,&B,&C,&K)
		&& (A || B || C || K))
	{
		a=C;
		b=((LL)1<<K);
		c=B-A;
		gcd(a,b,d,x,y);
		if(c%d==0){
			x*=c/d;
			bt=b/d;
			if(x<0){
				x=x%bt;
				if(x<0)x+=bt;;
			}
			else 
				x=x%bt;
			printf("%I64d\n",x);
		}
		else printf("FOREVER\n");
	}
	return 0;
}