#include<stdio.h>
const int MAX=510,INF=25000010;
int w[MAX][MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int F,N,M,W,S,E,T,i,j,k,ok,t;
	scanf("%d",&F);
	while(F--)
	{
		scanf("%d%d%d",&N,&M,&W);
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)w[i][j]=INF;
		for(i=0;i<N;i++)w[i][i]=0;
		for(i=0;i<M;i++){
			scanf("%d%d%d",&S,&E,&T);
			S--,E--;
			if(T<w[S][E])w[S][E]=w[E][S]=T;
		}
		for(i=0;i<W;i++){
			scanf("%d%d%d",&S,&E,&T);
			S--,E--;
			w[S][E]=-T;
		}


		ok=0;
		for(k=0;k<N;k++){
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					t=w[i][k]+w[k][j];
					if(t<w[i][j])w[i][j]=t;
				}
				if(w[i][i]<0){ok=1;break;}
			}
			if(ok)break;
		}

		printf("%s\n",ok?"YES":"NO");

	}
	return 0;
}