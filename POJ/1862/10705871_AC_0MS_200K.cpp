#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define LL __int64
const int MAX=50010,INF=1000010,MOD=7;
const double esp=1e-8,DNF=1e8;
struct cmp{
	bool operator()(const int a,const int b){
		return a<b;
	}
};
int n;
int main()
{
//	freopen("in.txt","r",stdin);
	double a,b,c;
	while(~scanf("%d",&n))
	{
		priority_queue<double,vector<double>,cmp> q;
		while(n--){
			scanf("%lf",&a);
			q.push(a);
		}
		while(q.size()>1){
			a=q.top();
			q.pop();
			b=q.top();
			q.pop();
			c=2*sqrt(a*b);
			q.push(c);
		}
		printf("%.3lf\n",q.top());
	}
    return 0;
}