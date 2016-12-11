#include<stdio.h>
#include<math.h>
const int MAX=160;
int po[MAX][2];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,cou,mid,max,rig,x0,y0,x1,y1,s;
	double k,b,r;
	while(~scanf("%d%d%lf",&x0,&y0,&r) && r>0)
	{
		max=0;
		scanf("%d",&n);
		for(i=0,cou=0;i<n;i++){
			scanf("%d%d",&x1,&y1);
			if( sqrt((double)((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)))<=r)
				po[cou][0]=x1,po[cou++][1]=y1;
		}

		for(i=0;i<cou;i++){
			mid=rig=0;
			if(po[i][0]==x0)
				for(j=0;j<cou;j++){
					if(po[j][0]==x0)mid++;
					else if(po[j][0]>x0)rig++;
				}
			else {
				k=(po[i][1]-y0)/(po[i][0]-x0);
				b=y0-k*x0;
				for(j=0;j<cou;j++){
					if((po[i][0]-x0)*(po[j][1]-y0)==(po[j][0]-x0)*(po[i][1]-y0))mid++;
					else if(k*po[j][0]-po[j][1]+b<0)rig++;
				}
			}
			s=rig+mid>cou-rig?rig+mid:cou-rig;
			if(s>max)max=s;
		}
		printf("%d\n",max);
	}
	return 0;
}