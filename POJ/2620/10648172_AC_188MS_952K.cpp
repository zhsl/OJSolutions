#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define max(a,b) ( (a>b)?a:b )
const int MAX=100010,INF=500010,MOD=7;
int cmp(const void *a,const void *b){
	return *(int*)a - *(int*)b;
}
int num[MAX][2]={-INF,0},ans[MAX][2];
int n,m,k;
int main()
{
	int i,ok,l,lmax,w,flag;
//	freopen("in.txt","r",stdin);
	while(~scanf("%d",&m))
	{
		k=ok=0;
		for(i=1;scanf("%d%d",&num[i][0],&num[i][1]) && (num[i][0] || num[i][1]);i++);
		n=i;

		qsort(num,n,sizeof(int)*2,cmp);
		for(flag=l=lmax=0,i=1;i<n;i++){
			if(num[i][0]>num[l][1]){
				if(!flag){ok=0;break;}
				else {
					ans[k][0]=num[w][0];
					ans[k++][1]=num[w][1];
					l=w,lmax=num[w][1];
					
					flag=0;
					i--;
				}
			}
			if(num[i][1]>num[l][1] && num[i][1]>lmax){
				if(num[i][1]>=m){
					ans[k][0]=num[i][0];
					ans[k++][1]=num[i][1];
					ok=1;break;
				}
				w=i;
				lmax=num[i][1];
				flag=1;
			}
		}

		if(ok){
			printf("%d\n",k);
			for(i=0;i<k;i++)
				printf("%d %d\n",ans[i][0],ans[i][1]);
		}
		else printf("No solution\n");
	}
	return 0;
}