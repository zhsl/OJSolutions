#include<stdio.h>
#include<string.h>
#define LL long long
#define pii pair<int,int>
const int MAX=13010,INF=1000000010,MOD=7;
int f[MAX],w[MAX],d[MAX];
int n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t;
	while(~scanf("%d%d",&n,&m))
	{
		memset(f,0,sizeof(f));
		for(i=0;i<n;i++)
			scanf("%d%d",&w[i],&d[i]);

		for(i=0;i<n;i++){
			for(j=m;j>=w[i];j--){
				t=f[j-w[i]]+d[i];
				if(t>f[j])f[j]=t;
			}
		}

		printf("%d\n",f[m]);
	}
	return 0;
}