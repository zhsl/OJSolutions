#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const LL MAX=33,MOD=9901;
LL power(LL a,LL n);
LL sum(LL &a,LL n);
LL num[MAX][2];
LL a,b;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,k;
	LL t,ans;
	while(~scanf("%I64d%I64d",&a,&b))
	{
		ans=1;
		memset(num,0,sizeof(num));
		for(t=a,k=0,i=2;t>1 && i*i<=t;i++){
			if(t%i==0){
				num[k][1]=i;
				while(t%i==0 && i<=t){
					t/=i;
				   	num[k][0]++;
				}
				k++;
			}
		}
		if(t>1){
			num[k][1]=t;
			num[k++][0]++;
		}
		for(i=0;i<k;i++){
			t=sum(num[i][1],num[i][0]*b);
			ans=(ans*t)%MOD;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

LL power(LL a,LL n){
	LL q;
	LL ans=1;
	for(q=n;q;q>>=1){
		if(q&1)ans=(ans*a)%MOD;
		a=(a*a)%MOD;
	}
	return ans;
}

LL sum(LL &a,LL n)
{
	if(!n)return 1;
	if(n&1) return ( sum(a,n>>1)*(power(a,(n>>1)+1)+1) )%MOD;
	return ( sum(a,n-1)+power(a,n) )%MOD;
}