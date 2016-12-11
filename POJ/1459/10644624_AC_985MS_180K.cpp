#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const int MAX=110,INF=100010;
int EK(int s);
int cap[MAX][MAX],fa[MAX],vis[MAX];
int n,np,nc,m,start,end;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,a,b,c;
	while(~scanf("%d%d%d%d",&n,&np,&nc,&m))
	{
		start=n,end=n+1;
		memset(cap,0,sizeof(cap));
		for(i=0;i<m;i++){
			scanf("%*[^(](%d,%d)%d",&a,&b,&c);
			if(a-b)cap[a][b]=c;
		}
		for(i=0;i<np;i++){
			scanf("%*[^(](%d)%d",&a,&b);
			cap[start][a]=b;
		}
		for(i=0;i<nc;i++){
			scanf("%*[^(](%d)%d",&a,&b);
			cap[a][end]=b;
		}
		
		printf("%d\n",EK(start));
	}
	return 0;
}

int EK(int s)
{
	int f=0,u,v;
	while(1){
		memset(vis,0,sizeof(vis));
		queue<int> q;
		q.push(s);
		vis[s]=INF;
		while(!q.empty())
		{
			u=q.front(),q.pop();
			for(v=0;v<=end;v++){
				if(!vis[v] && cap[u][v]>0){
					fa[v]=u,q.push(v);
					vis[v]=vis[u]<cap[u][v]?vis[u]:cap[u][v];
				}	
			}
		}
		if(!vis[end])return f;
		for(v=end;v!=s;v=fa[v])
			cap[fa[v]][v]-=vis[end];
		f+=vis[end];
	}
}