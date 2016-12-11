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
const int MAX=500010,INF=200000000;
const double esp=1e-6;
const int antiprime[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,
1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,
45360,50400,55440,83160,110880,166320,221760,277200,
332640,498960,554400,665280};// 反质数表
const int factorNum[]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,
90,96,100,108,120,128,144,160,168,180,192,200,216,224};
void update(int l,int r,int rt);
void getw();
struct People{
	char name[12];
	int v;
}a[MAX];
int ret[MAX<<2];
int n,k,w,tot,cou,ans;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,maxw,max;
	while(~scanf("%d%d",&n,&k))
	{
		memset(ret,0,sizeof(ret));
		for(i=0;antiprime[i]<=n;i++);
		i--;
		maxw=antiprime[i];
		max=factorNum[i];

		for(i=1;i<=n;i++)
			scanf("%s%d",a[i].name,&a[i].v);

		for(i=1,w=k,tot=n;i<=n;i++){
			cou=w;
			update(1,n,1);
			if(i==maxw)break;
			tot--;
			getw();
		}

		printf("%s %d\n",a[ans].name,max);
	}
	return 0;
}

void getw()
{
	int lsum;
	lsum=w-1;
	if(a[ans].v>0)
		w=(lsum+a[ans].v)%tot;	
	else 
		w=((lsum+a[ans].v)%tot+tot)%tot+1;
	if(!w)w=tot;
}

void update(int l,int r,int rt)
{
	if(l==r){
		ans=l;
		ret[rt]=1;
		return;
	}
	int mid=(l+r)>>1,t=mid-l+1-ret[rt<<1];
	if(t>=cou)
		update(lson);
	else {
		cou-=t;
		update(rson);
	}
	ret[rt]=ret[rt<<1]+ret[rt<<1|1];
}