#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const int MAX=110;
int map[MAX][MAX];
int n,w,h,s,t;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,ans,a,b,cou,p,q;
	while(scanf("%d",&n) && n)
	{
		ans=0;
		memset(map,0,sizeof(map));
		scanf("%d%d",&w,&h);
		for(i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			map[b-1][a-1]=1;
		}
		scanf("%d%d",&s,&t);

		for(i=0;i+t<=h;i++){
			for(j=0;j+s<=w;j++){
				for(p=i,cou=0;p<i+t;p++){
					for(q=j;q<j+s;q++)
						if(map[p][q])cou++;
				}
				if(cou>ans)ans=cou;
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}