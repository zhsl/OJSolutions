#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const int MAX=10010;
int cmp(const void *a,const void *b){
	int a1=*(int*)a,a2=*((int*)a+1),b1=*(int*)b,b2=*((int*)b+1);
	if(a1-b1)return b1-a1;
	return a2-b2;
}
int num[MAX],b[MAX][2];
int n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,a,t,k;
	while(~scanf("%d%d",&n,&m) && (n || m))
	{
		memset(num,0,sizeof(num));
		t=n;
		while(t--){
			for(i=0;i<m;i++){
				scanf("%d",&a);
				num[a]++;
			}
		}

		for(i=k=0;i<MAX;i++)
			if(num[i])b[k][0]=num[i],b[k++][1]=i;
		qsort(b,k,sizeof(int)*2,cmp);

		for(i=1;b[i][0]==b[0][0];i++);
		t=b[i][0];
		printf("%d",b[i][1]);
		for(i++;b[i][0]==t;i++)
			printf(" %d",b[i][1]);
		putchar('\n');
	}
	return 0;
}