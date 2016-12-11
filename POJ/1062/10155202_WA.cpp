#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAX=110;
int d[MAX][3],w[MAX][MAX],tr[MAX*MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,M,N,P,L,X,T,V,t,k,p,q,z,ok;
	while(~scanf("%d%d",&M,&N))
	{
		memset(w,0,sizeof(w));
		for(i=0;i<N;i++){
			scanf("%d%d%d",&P,&L,&X);
			d[i][0]=P,d[i][1]=L;
			for(j=0;j<X;j++){
				scanf("%d%d",&T,&V);
				w[i][T-1]=V;
			}

		}

		/*
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				printf("%2d",w[i][j]);
			putchar('\n');
		}
		*/
		for(i=0;i<N;i++)d[i][2]=i;
		for(k=0;k<N;k++){
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					if(w[i][j]){
						ok=1,q=0;
						tr[q++]=d[i][1];
						for(p=j;p!=d[p][2];p=d[p][2])
							tr[q++]=d[p][1];
						tr[q++]=d[p][1];	
						/*
						for(p=0;p<q;p++)
							printf("%2d",tr[p]);
						putchar('\n');
						*/
						for(p=0;p<q;p++){
							for(z=0;z<q;z++)
								if(abs(tr[p]-tr[z])>M){ok=0;break;}
							if(!ok)break;
						}
						t=w[i][j]+d[j][0];
						/*
						if(t==102){
							printf("adfadsfa ");
							for(p=0;p<q;p++)
							printf("%2d",tr[p]);
						putchar('\n');
						}
						*/
						if(t<d[i][0] && ok){
							d[i][0]=t;
							d[i][2]=j;
						}
					}
				}
			}
		}
		/*
		for(i=0;i<N;i++){
			printf("%d\n",d[i][2]);
		}
		*/
		printf("%d\n",d[0][0]);
	}
	return 0;
}