#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
const int MAX=8010,INF=10010,MOD=7;
const double esp=1e-3,DNF=1e8;
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
int num[510][MAX],vis[30010],vism[510];
int n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,ok1,ok2,ans;
	while(~scanf("%d%d",&n,&m) && (n || m))
	{
		memset(vis,0,sizeof(vis));
		memset(vism,0,sizeof(vism));
		ans=1;
		vis[0]=1;
		for(i=0;i<m;i++){
			scanf("%d",&num[i][0]);
			for(j=1;j<=num[i][0];j++)
				scanf("%d",&num[i][j]);
		}

		while(1){
			for(i=ok1=0;i<m;i++){
				if(!vism[i]){
					for(j=1,ok2=0;j<=num[i][0];j++){
						if(vis[num[i][j]]){
							for(j=1;j<=num[i][0];j++){
								if(!vis[num[i][j]])
									vis[num[i][j]]=1,ans++;
							}
							vism[i]=1;
							ok1=ok2=1;
						}
						if(ok2)break;
					}
				}
			}
			if(!ok1)break;
		}

		printf("%d\n",ans);
	}
	return 0;
}