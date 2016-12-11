#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<map>
#include<set>
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=501000,INF=200000000;
const double esp=1e-6;
set<int> q;
set<int>::iterator it;
int n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int a,l,r;
	char op[2];
	while(~scanf("%d%d",&n,&m))
	{
		stack<int> sta;
		q.clear();
		q.insert(0),q.insert(n+1);
		while(m--){
			scanf("%s",op);
			if(op[0]!='R'){
				scanf("%d",&a);
				if(op[0]=='D'){
					sta.push(a);
					q.insert(a);
				}
				else {
					it=q.lower_bound(a);
					if(*it==a){
						printf("0\n");
					}
					else {
						it--;
						l=*it;
						it++;
						r=*it;
						printf("%d\n",r-l-1);
					}
				}
			}
			else {
				a=sta.top();
				sta.pop();
				q.erase(a);
			}
		}
	}
	return 0;
}