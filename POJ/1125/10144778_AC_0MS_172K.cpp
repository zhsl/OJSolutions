#include<stdio.h>
const int MAX=110,INF=1010;
int n,d[MAX][MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,m,max,min,a,b,t,ans,ok;
	while(scanf("%d",&n) && n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				d[i][j]=INF;
		for(i=0;i<n;i++)
			d[i][i]=0;

		for(i=0;i<n;i++){
			scanf("%d",&m);
			for(j=0;j<m;j++){
				scanf("%d%d",&a,&b);
				d[i][a-1]=b;
			}
		}

		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++){
					t=d[i][k]+d[k][j];
					if(t<d[i][j])d[i][j]=t;
				}

		min=INF;
		for(i=0;i<n;i++){
			for(j=0,max=0,ok=1;j<n;j++){
				if(d[i][j]==INF){ok=0;break;}
				else if(d[i][j]>max)max=d[i][j];
			}
			if(max<min && ok)ans=i,min=max;
		}
		if(min!=INF)printf("%d %d\n",ans+1,min);
		else printf("disjoint\n");
	}
	return 0;
}