#include<stdio.h>
const int MAX=510,INF=25000010;
int u[MAX+MAX+200],v[MAX+MAX+200],w[MAX+MAX+200],d[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,f,n,tn,m,p,s,e,t,k,x,y,ok;
	scanf("%d",&f);
	while(f--)
	{
		scanf("%d%d%d",&n,&m,&p);
		for(i=0,k=0;i<m;i++){
			scanf("%d%d%d",&s,&e,&t);
			s--,e--;
			u[k]=v[k+1]=s;
			v[k]=u[k+1]=e;
			w[k]=w[k+1]=t;
			k+=2;
		}
		for(i=0;i<p;i++){
			scanf("%d%d%d",&s,&e,&t);
			s--,e--;
			u[k]=s,v[k]=e;
			w[k++]=-t;
		}

		for(i=0;i<k;i++)d[i]=INF;
		d[0]=0;
		ok=0;
		for(tn=n-1,i=0;i<tn;i++){
			for(j=0;j<k;j++){
				x=u[j],y=v[j];
				t=d[x]+w[j];
				if(t<d[y])d[y]=t;
			}
			for(j=0;j<k;j++){
				x=u[j],y=v[j];
				t=d[x]+w[j];
				if(t<d[y])ok=1;
			}
			if(ok)break;
		}

		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}