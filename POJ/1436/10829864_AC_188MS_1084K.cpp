#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
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
const int MAX=8010,INF=200000000;
const double esp=1e-6;
struct Node{
	int y1,y2,x;
}line[MAX];
int cmp(const void *a,const void *b){
	return ((Node*)a)->x - ((Node*)b)->x;
}
int ret[MAX<<3];
void update(int l,int r,int rt);
void pushdown(int rt);
void pushup(int rt);
int work();
int T,n,a,b,c;
vector<int> hash[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			hash[i].clear();
		for(i=0;i<n;i++)
			scanf("%d%d%d",&line[i].y1,&line[i].y2,&line[i].x);
		qsort(line,n,sizeof(Node),cmp);
		memset(ret,0,sizeof(ret));
		for(i=0;i<n;i++){
			c=i+1;
			a=line[i].y1<<1,b=line[i].y2<<1;
			update(0,16000,1);
		}

		printf("%d\n",work());
	}
	return 0;
}

void pushdown(int rt)
{
	if(ret[rt]>0){
		ret[rt<<1]=ret[rt<<1|1]=ret[rt];
		ret[rt]=-1;
	}
}

void pushup(int rt)
{
	if(ret[rt<<1]!=ret[rt<<1|1])
		ret[rt]=-1;
	if(ret[rt<<1]==ret[rt<<1|1])
		ret[rt]=ret[rt<<1];
}

void update(int l,int r,int rt)
{
	if(a<=l && r<=b && ret[rt]!=-1){
		if(ret[rt] && (hash[ret[rt]].size()==0 || 
			(hash[ret[rt]].size() && hash[ret[rt]][ hash[ret[rt]].size()-1 ]!=c) ))
			hash[ret[rt]].push_back(c);
		ret[rt]=c;
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(a<=mid)update(lson);
	if(b>mid)update(rson);
	pushup(rt);
}

int work()
{
	int i,j,k,ans=0,t,p,ok;
	for(k=1;k<=n;k++){
		for(i=0;i<hash[k].size();i++){
			for(j=i+1;j<hash[k].size();j++){
				t=hash[k][i];
				for(p=ok=0;p<hash[t].size();p++)
					if(hash[t][p]==hash[k][j]){
						ok=1;
						break;
					}
				ans+=ok;
			}
		}
	}
	return ans;
}