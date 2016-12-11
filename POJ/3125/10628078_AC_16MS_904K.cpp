#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
#define LL __int64
#define pii pair<int,int>
const int MAX=100010,INF=100000010;
int q[MAX][2];
int T,n,m;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,a,front,rear,max,maxw,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(q,0,sizeof(q));
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%d",&a);
			q[i][0]=a;
		}
		q[m][1]=1;
		front=0,rear=n;
		while(front<rear)
		{

			for(max=-1,i=front;i<rear;i++)
				if(q[i][0]>max)max=q[i][0],maxw=i;

			for(i=front;i<maxw;i++){
				q[rear][0]=q[i][0];
				q[rear++][1]=q[i][1];
			}
			ans++;
			if(q[maxw][1])break;
			front=maxw+1;	
		}
		printf("%d\n",ans);
	}
	return 0;
}