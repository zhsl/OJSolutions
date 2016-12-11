#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
const int MAX=10010,INF=10010,MOD=7;
const double esp=1e-3,DNF=1e8;
void fun(int a);
LL c[MAX];
int cou[MAX],num[MAX],p[20];
int n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,a;
	LL ans;
	memset(c,0,sizeof(c));
	for(i=4;i<MAX;i++)
		c[i]=(LL)i*(i-1)*(i-2)*(i-3)/24;
	while(~scanf("%d",&n))
	{
		ans=0;
		memset(cou,0,sizeof(cou));
		for(i=0;i<n;i++){
			scanf("%d",&a);
			fun(a);
		}
		
		for(i=2;i<MAX;i++)
			if(cou[i]){
				if(num[i]&1)
					ans+=c[cou[i]];
				else ans-=c[cou[i]];
			}

		printf("%I64d\n",c[n]-ans);
	}
	return 0;
}

void fun(int a)
{
	int i,j,k,max,val,t;
	for(i=2,k=0;i*i<=a;i++){
		if(a%i==0)p[k++]=i;
		while(a%i==0)a/=i;
	}
	if(a>1)p[k++]=a;
	max=(1<<k);
	for(i=1;i<max;i++){
		for(j=t=0,val=1;j<k;j++)
			if(i&(1<<j)){
				t++;
				val*=p[j];
			}
		cou[val]++;
		num[val]=t;
	}
}