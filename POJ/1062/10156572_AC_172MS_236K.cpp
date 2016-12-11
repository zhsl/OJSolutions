#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAX=110;
int d[MAX][2],tr[MAX],u[MAX*MAX],v[MAX*MAX],w[MAX*MAX],dd[MAX][2];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,M,N,P,L,X,T,V,t,k,min,max,a,b,m,ans;
	while(~scanf("%d%d",&M,&N))
	{
		min=0x7fffffff,max=0x80000000,ans=0x7fffffff;
		memset(w,0,sizeof(w));
		for(i=k=0;i<N;i++){
			scanf("%d%d%d",&P,&L,&X);
			dd[i][0]=P,dd[i][1]=L;
			if(L<min)min=L;
			if(L>max)max=L;
			for(j=0;j<X;j++){
				scanf("%d%d",&T,&V);
				u[k]=i,v[k]=T-1;
				w[k++]=V;
			}
		}

		m=k;
		for(a=min,b=a+M;a<=max;a++,b++){
			for(i=0;i<N;i++)d[i][0]=dd[i][0],d[i][1]=dd[i][1];		
			for(i=0;i<N;i++){
				for(j=0;j<m;j++){
					int x=u[j],y=v[j];
					if(d[x][1]>=a&&d[x][1]<=b && d[y][1]>=a&&d[y][1]<=b){
						t=d[y][0]+w[j];
						if(t<d[x][0])d[x][0]=t;
					}
				}
			}
			if(d[0][0]<ans)ans=d[0][0];
		}
		printf("%d\n",ans);
	}
	return 0;
}