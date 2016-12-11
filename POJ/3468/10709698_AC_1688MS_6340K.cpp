#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=100010,INF=1000010,MOD=7;
const double esp=1e-3,DNF=1e8;
struct Node{
	int l,r;
	LL sum,lnc;
}tree[MAX*4];
void con(int l,int r,int k);
void update(int l,int r,int k,LL c);
void search(int l,int r,int k);
int n,m;
LL sum;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,y;
	char s[2];
	LL a,val;
	while(~scanf("%d%d",&n,&m))
	{
		con(1,n,1);
		for(i=1;i<=n;i++){
			scanf("%I64d",&a);
			update(i,i,1,a);
		}
		while(m--){
			scanf("%s",s);
			if(s[0]=='Q'){
				sum=0;
				scanf("%d%d",&x,&y);
				search(x,y,1);
				printf("%I64d\n",sum);
			}
			else {
				scanf("%d%d%I64d",&x,&y,&val);
				update(x,y,1,val);
			}
		}
	}
	return 0;
}

void con(int l,int r,int k)
{
	tree[k].l=l;
	tree[k].r=r;
	tree[k].sum=tree[k].lnc=0;
	if(l==r)return;
	int mid;
	mid=(l+r)>>1;
	con(l,mid,k<<1);
	con(mid+1,r,(k<<1)+1);
	return;
}

void update(int l,int r,int k,LL c)
{
	if(tree[k].l==l && tree[k].r==r){
		tree[k].lnc+=c;
		return;
	}
	tree[k].sum+=(r-l+1)*c;
	int mid;
	mid=(tree[k].l+tree[k].r)>>1;
	if(r<=mid)
		update(l,r,k<<1,c);
	else if(l>mid)
		update(l,r,(k<<1)+1,c);
	else {
		update(l,mid,k<<1,c);
		update(mid+1,r,(k<<1)+1,c);
	}
	return;
}

void search(int l,int r,int k)
{
	if(tree[k].l==l && tree[k].r==r){
		sum+=tree[k].sum+(tree[k].r-tree[k].l+1)*tree[k].lnc;
		return;
	}
	else {
		tree[k<<1].lnc+=tree[k].lnc;
		tree[(k<<1)+1].lnc+=tree[k].lnc;
		tree[k].sum+=(tree[k].r-tree[k].l+1)*tree[k].lnc;
		tree[k].lnc=0;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(r<=mid)
		search(l,r,k<<1);
	else if(l>mid)
		search(l,r,(k<<1)+1);
	else {
		search(l,mid,k<<1);
		search(mid+1,r,(k<<1)+1);
	}
	return;
}