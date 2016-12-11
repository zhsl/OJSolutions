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
const int MAX=65536*2,INF=200000000;
const double esp=1e-6;
void update(int l,int r,int rt);
void query(int l,int r,int rt);
void pushdown(int rt);
int cover[MAX<<2],flag[MAX<<2],ans[MAX];
int a,b,c,n=MAX-1;
char op[2];
void work(int rt) {
	if (cover[rt] != -1) cover[rt] ^= 1;
	else flag[rt] ^= 1;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int i,ta,tb,ok;
	char lc,rc;
	while(~scanf("%s %c%d,%d%c",op,&lc,&a,&b,&rc))
	{
		ta=(a<<1)+(lc=='(');
		tb=(b<<1)-(rc==')');
		if(op[0]=='U' || op[0]=='D'){
			c=(op[0]=='U');
			a=ta,b=tb;
			update(0,n,1);
		}
		if(op[0]=='I' || op[0]=='C'){
			c=0;
			b=ta-1,a=0;
			update(0,n,1);
			a=tb+1,b=n;
			update(0,n,1);
		}
		if(op[0]=='C' || op[0]=='S'){
			c=-1;
			a=ta,b=tb;
			update(0,n,1);
		}
	}	
	query(0,n,1);
	for(i=ok=0;i<=n;i++){
		if(ans[i]){
			ok++;
			for(a=i;ans[i+1];i++);
			b=i;
			lc=(a&1)?'(':'[';
			rc=(b&1)?')':']';
			a>>=1,b=(b+1)>>1;
			if(ok>1)putchar(' ');
			printf("%c%d,%d%c",lc,a,b,rc);
		}
	}
	if(!ok)printf("empty set");
	putchar('\n');
	return 0;
}

void pushdown(int rt)
{
	if(cover[rt]!=-1){
		cover[rt<<1]=cover[rt<<1|1]=cover[rt];
		flag[rt<<1]=flag[rt<<1|1]=0;
		cover[rt]=-1;	
	}
	if(flag[rt]){
		work(rt<<1);
		work(rt<<1|1);
		flag[rt]=0;
	}
}

void update(int l,int r,int rt)
{
	if(c>=0 && cover[rt]==c)return;
	if(a<=l && r<=b){
		if(c!=-1){
			cover[rt]=c;
			flag[rt]=0;
		}
		else if(cover[rt]!=-1){
			cover[rt]^=1;
			flag[rt]=0;
		}
		else 
			flag[rt]^=1;
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(a<=mid)
		update(lson);
	if(b>mid)
		update(rson);
}

void query(int l,int r,int rt)
{
	if(!cover[rt])
		return;
	if(cover[rt]==1){
		int i;
		for(i=l;i<=r;i++)
			ans[i]=1;
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	query(lson);
	query(rson);
}