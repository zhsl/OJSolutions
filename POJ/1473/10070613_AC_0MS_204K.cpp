#include<stdio.h>
#include<math.h>
#include<string>
#include<map>
const int MAX=210;
const double XY=sqrt(2.0)/2;
using namespace std;
struct DIR
{
	double x,y;
};
map<string,DIR> dir;
int main()
{
//	freopen("in.txt","r",stdin);
	dir["N"].x=0,dir["N"].y=1,dir["S"].x=0,dir["S"].y=-1;
	dir["W"].x=-1,dir["W"].y=0,dir["E"].x=1,dir["E"].y=0;
	dir["NW"].x=-XY,dir["NW"].y=XY,dir["NE"].x=XY,dir["NE"].y=XY;
	dir["SW"].x=-XY,dir["SW"].y=-XY,dir["SE"].x=XY,dir["SE"].y=-XY;
	int i,j,k,num,t=1;
	double x,y,s;
	char c[MAX],a[20],b[20];
	while(scanf("%s",c) && c[0]!='E')
	{
		x=y=0;
		for(i=0,j=0;c[i]!='\0';j++,i=j){
			for(k=0;c[j]!=',' && c[j]!='.';j++,k++)a[k]=c[j];
			a[k]='\0';
			sscanf(a,"%d%s",&num,b);
			x+=num*dir[b].x,y+=num*dir[b].y;
		}
		s=sqrt(x*x+y*y);

		printf("Map #%d\n",t++);
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
		printf("The distance to the treasure is %.3lf.\n\n",s);
	}
	return 0;
}