#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=50010,INF=200010,MOD=7;
const double esp=1e-8,DNF=1e8;
struct Tree{
	int l,r;
	int max,min;
}tree[MAX*4];
void construct(int l,int r,int k);
void update(int l,int r,int k,int c);
void search(int l,int r,int k);
int n,m,a,min,max;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,y;
	while(~scanf("%d%d",&n,&m))
	{
		construct(1,n,1);
		for(i=0;i<n;i++){
			scanf("%d",&a);
			update(i,i,1,a);
		}

		for(i=0;i<m;i++){
			min=INF;
			max=-INF;
			scanf("%d%d",&x,&y);
			search(x,y,1);
			printf("%d\n",max-min);
		}
	}
    return 0;
}

void construct(int l,int r,int k)
{
	int mid;
	tree[k].l=l,tree[k].r=r;
	tree[k].min=INF,tree[k].max=-INF;
	if(l==r)return;
	mid=(l+r)>>1;
	construct(l,mid,k<<1);
	construct(mid+1,r,(k<<1)+1);
	return;
}

void update(int l,int r,int k,int c)
{
	int mid;
	if(c<tree[k].min)tree[k].min=c;
	if(c>tree[k].max)tree[k].max=c;
	if(tree[k].l==tree[k].r)return;
	mid=(tree[k].l+tree[k].r)>>1;
	if(r<=mid)
		update(l,r,k<<1,c);
	else if(l>mid)
		update(l,r,(k<<1)+1,c);
	else{
		update(l,mid,k<<1,c);
		update(mid+1,r,(k<<1)+1,c);
	}
	return;
}

void search(int l,int r,int k)
{
	int mid;
	if(tree[k].l==l && tree[k].r==r){
		if(tree[k].min<min)min=tree[k].min;
		if(tree[k].max>max)max=tree[k].max;
		return;
	}
	mid=(tree[k].l+tree[k].r)>>1;
	if(r<=mid)
		search(l,r,k<<1);
	else if(l>mid)
		search(l,r,(k<<1)+1);
	else{
		search(l,mid,k<<1);
		search(mid+1,r,(k<<1)+1);
	}
	return;
}