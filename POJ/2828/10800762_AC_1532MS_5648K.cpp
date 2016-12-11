#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
#include<map>
#include<set>
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=200010,INF=200000000;
const double esp=1e-6;
int update(int l,int r,int rt);
struct People{
	int p,v;
}a[MAX];
int ans[MAX],ret[MAX<<2];
int n,p,sum;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,t,k;
	while(~scanf("%d",&n))
	{
		k=0;
		memset(ret,0,sizeof(ret));
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].p,&a[i].v);

		for(i=n-1;i>=0;i--){
			sum=0;
			p=a[i].p+1;
			t=update(0,n-1,1);
			if(t==k)k++;
			ans[t]=i;
		}

		printf("%d",a[ans[0]].v);
		for(i=1;i<n;i++)
			printf(" %d",a[ans[i]].v);
		putchar('\n');
	}
	return 0;
}

int update(int l,int r,int rt)
{
	if(l==r){
		sum++;
		ret[rt]=1;
		return l;
	}
	int mid=(l+r)>>1,t=mid-l+1-ret[rt<<1],ans;
	if(t>=p-sum)
		ans=update(lson);
	else {
		sum+=t;
		ans=update(rson);
	}
	ret[rt]=ret[rt<<1]+ret[rt<<1|1];
	return ans;
}