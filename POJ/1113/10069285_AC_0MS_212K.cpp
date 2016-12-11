#include<stdio.h>
#include<stdlib.h>
#include<math.h>
const double PI=acos(-1.0);
const int MAX=1010;
int cmp(const void *a,const void *b);
int ramham();
int N,L,sta[MAX][2],xy[MAX][2],min_x,min_y,top;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,x1,y1,x2,y2,xa,ya;
	double s,t;
	while(~scanf("%d%d",&N,&L))
	{
		min_x=0x7fffffff;
		for(i=0;i<N;i++){
			scanf("%d %d",&xy[i][0],&xy[i][1]);
			if(xy[i][0]<min_x || (xy[i][0]==min_x && xy[i][1]<min_y))
				min_x=xy[i][0],min_y=xy[i][1];
		}
		
		qsort(xy,N,sizeof(int)*2,cmp);
		ramham();

		s=0;
		sta[top][0]=min_x,sta[top++][1]=min_y;
		x1=sta[0][0],y1=sta[0][1];
		for(i=1;i<top;i++){
			x2=sta[i][0],y2=sta[i][1];
			xa=x2-x1,ya=y2-y1;
			t=xa*xa+ya*ya;
			s+=sqrt(t);
			x1=x2,y1=y2;
		}
		s+=2*PI*L;
		printf("%.0lf\n",s);
	}
	return 0;
}

int cmp(const void *a,const void *b)
{
	int x1=*(int*)a-min_x,y1=*((int*)a+1)-min_y,
		x2=*(int*)b-min_x,y2=*((int*)b+1)-min_y;
	int k=x1*y2-x2*y1;
	if(k>0)return -1;
	else if(k<0)return 1;
	else if(x1*x1+y1*y1<x2*x2+y2*y2)return -1;
	else return 1;
}

int ramham()
{
	top=0;
	int i,x1,y1,x2,y2,x3,y3,t;
	sta[top][0]=xy[0][0],sta[top++][1]=xy[0][1];
	sta[top][0]=xy[1][0],sta[top++][1]=xy[1][1];
	sta[top][0]=xy[2][0],sta[top++][1]=xy[2][1];
	for(i=3;i<N;i++){
		x3=xy[i][0],y3=xy[i][1];
		x2=sta[top-1][0],y2=sta[top-1][1];
		x1=sta[top-2][0],y1=sta[top-2][1];
		t=(x1-x2)*(y3-y2)-(x3-x2)*(y1-y2);
		while(t>0){
			top--;
			x3=xy[i][0],y3=xy[i][1];
			x2=sta[top-1][0],y2=sta[top-1][1];
			x1=sta[top-2][0],y1=sta[top-2][1];
			t=(x1-x2)*(y3-y2)-(x3-x2)*(y1-y2);
		}
		sta[top][0]=xy[i][0],sta[top++][1]=xy[i][1];
	}
	return 1;
}