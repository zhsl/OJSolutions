#include<stdio.h>
#include<algorithm>
using namespace std;
int find(int x);
void Kruskal();
int cmp(const int i,const int j);
struct POINT
{
	int u,v,w;
}point[125010];
int fa[510],r[125010],ans,n,m,T;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0,m=0;i<n;i++)
			for(j=0;j<n;j++){
				scanf("%d",&t);
				if(t && j>i){
					point[m].u=i,point[m].v=j;
					point[m++].w=t;
				}
			}

		Kruskal();
		
		printf("%d\n",ans);
	}
	return 0;
}

void Kruskal()
{
	ans=0x80000000;
	int i,e,x,y;
	for(i=0;i<n;i++)fa[i]=i;
	for(i=0;i<m;i++)r[i]=i;
	sort(r,r+m,cmp);	
	for(i=0;i<m;i++){
		e=r[i];
		x=find(point[e].u);
		y=find(point[e].v);
		if(x!=y){
			if(point[e].w>ans)
				ans=point[e].w;
			fa[x]=y;
		}
	}
}

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int cmp(const int i,const int j)
{
	return point[i].w<point[j].w;
}