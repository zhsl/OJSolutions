#include<stdio.h>
#include<algorithm>
using namespace std;
int find(int x);
void Kruskal();
int cmp(const int i,const int j);
struct POINT
{
	int u,v,w;
}point[5010];
int fa[110],r[5010],ans,n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t;
	while(~scanf("%d",&n))
	{
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
	ans=0;
	int i,e,x,y;
	for(i=0;i<n;i++)fa[i]=i;
	for(i=0;i<m;i++)r[i]=i;
	sort(r,r+m,cmp);	
	for(i=0;i<m;i++){
		e=r[i];
		x=find(point[e].u);
		y=find(point[e].v);
		if(x!=y)ans+=point[e].w,fa[x]=y;
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