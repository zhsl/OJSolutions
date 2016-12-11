#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
const int MAX=110,INF=200000010,MOD=7;
const double esp=1e-3,DNF=1e8;
struct Line{
	int x1,y1,x2,y2;
}line[MAX];
int is_outside(Line &a);
int quick(Line &a,Line &b);
int l,w,T,n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	int ans[3],s;
	scanf("%d",&T);
	while(T--)
	{
		s=0;
		memset(ans,0,sizeof(ans));
		scanf("%d%d%d",&l,&w,&n);
		for(i=0;i<n;i++){
			scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
			if(!ans[1] && is_outside(line[i]))
				ans[1]=1;
		}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(quick(line[i],line[j]))
					ans[0]=1;
				if(ans[0])break;
			}
			if(ans[0])break;
		}

		if(!ans[0] && !ans[1]){
			for(i=0;i<n;i++){
				s+=(line[i].y2-line[i].y1)
					*(line[i].x2-line[i].x1);
			}
			if(s==l*w)ans[2]=1;
		}
		if(ans[0])printf("NONDISJOINT\n");
		else if(ans[1])printf("NONCONTAINED\n");
		else if(!ans[2])printf("NONCOVERING\n");
		else printf("OK\n");
	}
	return 0;
}

int quick(Line &a,Line &b)
{
	if( a.x1>=b.x2 ||
		a.y1>=b.y2 ||
		a.x2<=b.x1 ||
		a.y2<=b.y1)
		return 0;
	return 1;
}

int is_outside(Line &a)
{
	if( a.x1<0 || a.y1<0 ||
		a.x2>l || a.y2>w )
		return 1;
	return 0;
}