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
const int MAX=100010;
int s[MAX],vis[MAX];
int T,n;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,p,k,t,cou,flag;
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for(i=k=t=0;i<n;i++){
			scanf("%d",&p);
			k+=p-t;
			s[k++]=1;
			t=p;
		}

		flag=0;
		for(i=0;i<k;i++){
			if(s[i]){
				for(j=i-1,cou=1;j>=0;j--){
					if(!s[j] && !vis[j]){
						if(flag)printf(" %d",cou);
						else flag=1,printf("%d",cou);
						vis[i]=vis[j]=1;
						break;
					}
					if(s[j] && vis[j])cou++;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}