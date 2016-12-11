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
const int MAX=110;
int EK(int s);
int cap[MAX][MAX],flow[MAX][MAX],fa[MAX],vis[MAX],pc[MAX],pcl[MAX];
int n,np,nc,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,ans,a,b,c;
	while(~scanf("%d%d%d%d",&n,&np,&nc,&m))
	{
		ans=0;
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(pcl,0,sizeof(pcl));
		memset(pc,0,sizeof(pc));
		for(i=0;i<m;i++){
			scanf("%*[^(](%d,%d)%d",&a,&b,&c);
			cap[a][b]=c;
		}
		for(i=0;i<np;i++){
			scanf("%*[^(](%d)%d",&a,&b);
			pc[a]=b;
		}
		for(i=0;i<nc;i++){
			scanf("%*[^(](%d)%d",&a,&b);
			pc[a]=-b;
		}
		
		for(i=0;i<n;i++){
			if(pc[i]>0)
				ans+=EK(i);
		}

		printf("%d\n",ans);
	}
	return 0;
}

int EK(int s)
{
	int t,ok,f=0,u,v;
	while(1){
		memset(vis,0,sizeof(vis));
		queue<int> q;
		q.push(s);
		vis[s]=pc[s]-pcl[s];
		ok=0;
		while(!q.empty())
		{
			u=q.front(),q.pop();
			for(v=0;v<n;v++){
				if(!vis[v] && cap[u][v]>flow[u][v]){
					fa[v]=u,q.push(v);
					t=cap[u][v]-flow[u][v];
					vis[v]=vis[u]<t?vis[u]:t;
					if(pc[v]<0 && -pc[v]-pcl[v]>0){
						ok=1;
						t=-pc[v]-pcl[v];
						vis[v]=vis[v]<t?vis[v]:t;
						break;
					}
				}	
			}
			if(ok)break;
		}
		if(!ok)return f;
		t=vis[v];
		pcl[v]+=t;
		pcl[s]+=t;
		for(;v!=s;v=fa[v]){
			flow[fa[v]][v]+=t;
			flow[v][fa[v]]-=t;
		}
		f+=t;
		if(pcl[s]==pc[s])return f;	
	}
	return f;
}