#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const int MAX=1010,INF=1000000000;
int mutil(int *a,int n,int len);
int bj(int *a,int *b);
int a[MAX],b[MAX];
int n,len;
char s[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int k;
	double p,t;
	while(~scanf("%d%lf",&n,&p))
	{
		 t=pow(p,1/(double)n);
		 k=(floor(t)-t>0.5)?(int)t:(int)(t+0.5);
		 printf("%d\n",k);
	}
	/*
	int i,j,mid,low,high,t;
	while(~scanf("%d%s",&n,s))
	{
		len=strlen(s);
		for(i=0;i<len;i++)
			a[i]=s[len-i-1];

		low=0,high=INF;
		while(low<high){
			memset(b,0,sizeof(b));
			mid=(low+high)>>1;
			for(t=mid,i=0;t;t/=10,i++)b[i]=t%10;
			mutil(b,n,i);
			t=bj(a,b);
			if(t>0)
				low=mid;
			else if(t<0)high=mid;
			else break;
		}

		printf("%d\n",mid);
	}
	*/
	return 0;
}
/*
int mutil(int *a,int n,int len)
{
	int i,j,t,c[MAX],lenc;
	memset(c,0,sizeof(c));
	while(--n){
		for(i=0;i<len;i++){
			for(j=t=0;j<len || t;j++){
				t=b[i]*b[j]+t;
				c[i+j]=t%10;
				t/=10;
			}
			lenc=i;
		}
	}
	for(i=0;i<lenc;i++)
		a[i]=c[i];
	return 1;
}

int bj(int *a,int *b)
{
	int i,lena,lenb;
	for(lena=MAX-1;a[lena];lena--);
    for(lenb=MAX-1;a[lenb];lenb--);
	if(lena<lenb)return 1;
	else if(lena>lenb)return -1;
	else {
		for(i=lena;i>=0;i--){
			if(a[i]<b[i])return 1;
			else if(a[i]>b[i])return -1;
		}
	}
	return 0;
}
*/