#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=1000010,INF=100000000,MOD=7;
struct Node{
	int val,w;
}qmin[MAX],qmax[MAX];
int ans[MAX][2];
int n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,fmin,rmin,fmax,rmax,len,a;
	while(~scanf("%d%d",&n,&m))
	{
		fmin=rmin=0;
		fmax=rmax=0;
		m--;
		for(i=0;i<n;i++){
			scanf("%d",&a);
			while(fmin<rmin && qmin[rmin-1].val>=a)rmin--;
			qmin[rmin].val=a;
			qmin[rmin++].w=i;
			while(qmin[fmin].w<i-m)fmin++;
			if(i>=m)ans[i-m][0]=qmin[fmin].val;

			while(fmax<rmax && qmax[rmax-1].val<=a)rmax--;
			qmax[rmax].val=a;
			qmax[rmax++].w=i;
			while(qmax[fmax].w<i-m)fmax++;
			if(i>=m)ans[i-m][1]=qmax[fmax].val;
		}
		len=n-m;
		printf("%d",ans[0][0]);
		for(i=1;i<len;i++)
			printf(" %d",ans[i][0]);
		putchar('\n');
		printf("%d",ans[0][1]);
		for(i=1;i<len;i++)
        	printf(" %d",ans[i][1]);
		putchar('\n');
	}
    return 0;
}