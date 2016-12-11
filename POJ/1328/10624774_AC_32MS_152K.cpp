#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const int MAX=1010,INF=2000000100;
int cmp(const void *a,const void *b){
	double t=*(double*)a - *(double*)b;
	if(t>0)return 1;
	if(t<0)return -1;
	else return 0;
}
int n;
double x0,d,num[MAX][2];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,k=1,ans;
	double nx,nxl,nxr,t;
	while(scanf("%d%lf",&n,&d) && (n || d))
	{
		ans=0;	
		for(i=0;i<n;i++)
			scanf("%lf%lf",&num[i][0],&num[i][1]);
		qsort(num,n,sizeof(double)*2,cmp);

		x0=-INF;
		if(d>=0){
			for(i=0;i<n;i++){
				t=d*d-num[i][1]*num[i][1];
				if(t<0 || num[i][1]<0){ans=-1;break;}
				nx=sqrt(t);
				nxl=num[i][0]-nx;
				nxr=num[i][0]+nx;
				if(nxr<x0)x0=nxr;
				else if(nxl>x0){
					ans++;
					x0=nxr;
				}
			}
		}
		else ans=-1;

		printf("Case %d: %d\n",k++,ans);
	}
	return 0;
}