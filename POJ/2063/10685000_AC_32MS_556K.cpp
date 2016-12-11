#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=100010,INF=1000,MOD=7;
int f[MAX],v[15],w[15];
int T,val,yer,n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,valt,t;
	scanf("%d",&T);
	while(T--)
	{	
		memset(f,0,sizeof(f));
		scanf("%d%d%d",&val,&yer,&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&v[i],&w[i]);
			v[i]/=INF;
		}

		while(yer--){
			valt=val/INF;
			for(i=0;i<n;i++){
				for(j=v[i];j<=valt;j++){
					t=f[j-v[i]]+w[i];
					if(t>f[j])f[j]=t;
				}
			}
			val+=f[valt];
		}

		printf("%d\n",val);
	}
    return 0;
}