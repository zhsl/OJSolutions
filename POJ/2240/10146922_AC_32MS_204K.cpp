#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
const int MAX=30,INF=0;
map<string,int> p;
int n,m;
double d[MAX][MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,ok,x,y,cou=1;
	double w,t;
	char c1[MAX],c2[MAX];
	while(scanf("%d",&n) && n)
	{
		memset(d,0,sizeof(d));
		for(i=0;i<n;i++){
			scanf("%s",c1);
			p[c1]=i;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%s %lf %s",c1,&w,c2);
			x=p[c1],y=p[c2];
			d[x][y]=w;
		}

		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++){
					t=d[i][k]*d[k][j];
					if(t>d[i][j])d[i][j]=t;
				}
		ok=0;
		for(i=0;i<n;i++)
			if(d[i][i]>1){ok=1;break;}

		printf("Case %d: %s\n",cou++,ok?"Yes":"No");
	}
	return 0;
}