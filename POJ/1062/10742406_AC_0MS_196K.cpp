#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
#define LL __int64
const int MAX=110,INF=200000000;
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
int DFS(int x);
int w[MAX][MAX],l[MAX],val[MAX],dp[MAX];
int m,n,low,high;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,v,y,ans,minl,maxl,t;
	while(~scanf("%d%d",&m,&n))
	{
		ans=INF;
		minl=INF;
		maxl=-INF;
		memset(w,-1,sizeof(w));
		for(i=0;i<n;i++){
			scanf("%d%d%d",&val[i],&l[i],&k);
			if(l[i]<minl)minl=l[i];
			if(l[i]>maxl)maxl=l[i];
			for(j=0;j<k;j++){
				scanf("%d%d",&y,&v);
				w[i][--y]=v;
			}
		}
		for(low=minl,high=minl+m;low<=maxl;low++,high++){
			memset(dp,-1,sizeof(dp));
			t=INF;
			if(l[0]>=low && l[0]<=high)
				t=DFS(0);
			if(t<ans)ans=t;
		}

		printf("%d\n",ans);
	}
	return 0;
}

int DFS(int x)
{
	int& ans=dp[x];
	if(ans!=-1)return ans;
	ans=val[x];
	int i;
	for(i=0;i<n;i++)
		if(w[x][i]!=-1 && l[i]>=low && l[i]<=high)
			ans=min(ans,DFS(i)+w[x][i]);
	return ans;
}