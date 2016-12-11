#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
#define LL __int64
const int MAX=310,INF=200000000;
int n;
int s(int a);
int main()
{
//	freopen("in.txt","r",stdin);
	int i,t,max,sum1,sum2;
	while(~scanf("%d",&n) && n){
		while(n++){
			t=n;
			sum2=0;
			if(t!=2){
				while(!(t&1)){
					t>>=1;
					sum2+=2;
				}
			}
			max=(int)sqrt((double)t)+1;
			for(i=3;i<=max && t>1;i+=2)
				while(t%i==0){
					t/=i;
					sum2+=s(i);
				}
			if(t!=n){
				if(t>1)sum2+=s(t);
				sum1=s(n);
				if(sum1==sum2)break;
			}
		}
		
		printf("%d\n",n);
	}
	return 0;
}

int s(int a)
{
	int sum=a%10;
	while(a/=10)
		sum+=a%10;
	return sum;
}