#include<stdio.h>
const int MAX=100010;
struct Tree
{
	int l,r;
	int c;
}t[MAX*4];
int construct(int l,int r,int k);
int insert(int l,int r,int c,int k);
int search(int l,int r,int k,int& ans);
int L,T,O;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,a,b,c,ans,k;
	char way;
	while(~scanf("%d%d%d",&L,&T,&O))
	{
		construct(0,L,1);

		for(i=0;i<O;i++){
			getchar();
			scanf("%c",&way);
			if(way=='C'){
				scanf("%d%d%d",&a,&b,&c);
				insert(a,b,c,1);
			}
			else{
				scanf("%d%d",&a,&b);
				k=0;
				search(a,b,1,k);
				for(j=ans=0;j<30;j++)
					if( k&(1<<j) )ans++;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}

int construct(int l,int r,int k)
{
	t[k].l=l,t[k].r=r;
	t[k].c=1;
	if(l==r)return 1;
	int mid=(l+r)/2;
	construct(l,mid,2*k);
	construct(mid+1,r,2*k+1);
	return 1;
}

int insert(int l,int r,int c,int k)
{
	if(t[k].l==l && t[k].r==r){
		t[k].c=(1<<c);
		return 1;
	}
	if(t[k].c!=c){
		t[2*k].c=t[k].c;
		t[2*k+1].c=t[k].c;
		t[k].c|=c;
	}
	int mid=(t[k].l+t[k].r)/2;
	if(r<=mid)
		insert(l,r,c,2*k);
	else if(l>mid)
		insert(l,r,c,2*k+1);
	else{
		insert(l,mid,c,2*k);
		insert(mid+1,r,c,2*k+1);
	}
	return 1;
}

int search(int l,int r,int k,int& ans)
{
	if(t[k].l==l && t[k].r==r){
		ans|=t[k].c;
		return 1;
	}
	int mid=(t[k].l+t[k].r)/2;
	if(r<=mid)
		search(l,r,2*k,ans);
	else if(l>mid)
		search(l,r,2*k+1,ans);
	else{
		search(l,mid,2*k,ans);
		search(mid+1,r,2*k+1,ans);
	}
	return 1;
}