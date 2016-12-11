#include<stdio.h>
#include<string.h>
const int MAX1=10000010,MAX2=10010;
void construct(int l,int r,int k);
void insert(int l,int r,int k,int c);
void search(int k);
struct TREE
{
	int l,r,c;
}tree[MAX2*8];
short fa[MAX1];
int num[MAX2][3],vis[MAX2*2];
int all,T,ans;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,n;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(fa,0,sizeof(fa));
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&num[i][0],&num[i][1]);
			fa[num[i][0]]=1;
			fa[num[i][1]]=1;
			num[i][2]=i+1;
		}
		for(i=0,all=1;i<MAX1;i++)
			if(fa[i])fa[i]=all++;
		construct(1,all-1,1);
		for(i=0;i<n;i++)
			insert(fa[ num[i][0] ],fa[ num[i][1] ],num[i][2],1);
		search(1);
		printf("%d\n",ans);
	}
	return 0;
}

void construct(int l,int r,int k)
{
	tree[k].l=l;tree[k].r=r;
	tree[k].c=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	construct(l,mid,k<<1);
	construct(mid+1,r,k<<1|1);
	return;
}

void insert(int l,int r,int c,int k)
{
	if(tree[k].l==l && tree[k].r==r || tree[k].c==c){
		tree[k].c=c;
		return;
	}
	if(tree[k].c>0){
		tree[k<<1].c=tree[k].c;
		tree[k<<1|1].c=tree[k].c;
		tree[k].c=0;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(r<=mid)
		insert(l,r,c,k<<1);
	else if(l>mid)
		insert(l,r,c,k<<1|1);
	else {
		insert(l,mid,c,k<<1);
		insert(mid+1,r,c,k<<1|1);
	}
	return;
}

void search(int k)
{
	if(tree[k].c){
		if(!vis[tree[k].c]){ans++;vis[tree[k].c]=1;}
		return;
	}
	search(k<<1);
	search(k<<1|1);
	return;
}