#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL __int64
#define pii pair<int,int>
const int MAX=110,INF=2000000010,MOD=7;
void DFS(int cur,int a,int k);
int ok1(int a,int b);
int ok2(int a,int b);
int sta[MAX],map[110],f[110][MAX][MAX],stanum[MAX],vis[200000];
int n,m,all;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t,p,max,ans;
	char s[15];
	while(~scanf("%d%d",&n,&m))
	{
		ans=all=0;
		memset(map,0,sizeof(map));
		memset(f,0,sizeof(f));
		memset(sta,0,sizeof(sta));
		memset(stanum,0,sizeof(stanum));
		memset(vis,0,sizeof(vis));
		DFS(0,0,0);
		
		n++;
		for(i=2;i<=n;i++){
			scanf("%s",s);
			for(j=0;j<m;j++)
				if(s[j]=='H')map[i]|=(1<<j);
		}

		for(i=2;i<=n;i++){
			for(k=0;k<all;k++){
				if( !(map[i]&sta[k]) ){
					for(j=0;j<all;j++){
						if( !(sta[k]&sta[j]) && !(map[i-1]&sta[j]) ){
							for(p=max=0;p<all;p++)
								if( !(sta[k]&sta[p]) && !(sta[j]&sta[p]) && !(map[i-2]&sta[p])){
									t=f[i-1][j][p]+stanum[k];
									if(t>max)max=t;
								}
						}
						f[i][k][j]=max;
					}
				}
			}
		}
		for(i=0;i<all;i++)
			for(j=0;j<all;j++)
				if(f[n][i][j]>ans)ans=f[n][i][j];

		printf("%d\n",ans);
	}
	return 0;
}

void DFS(int cur,int a,int k)
{
	if(!vis[a]){
		sta[all]=a;
		stanum[all++]=k;
		vis[a]=1;
	}
	if(cur>=m)return;
	DFS(cur+3,a|(1<<cur),k+1);
	DFS(cur+1,a,k);
}