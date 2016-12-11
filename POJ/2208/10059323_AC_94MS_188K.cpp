#include<stdio.h>
#include<math.h>
double l[7];
int main()
{
//	freopen("in.txt","r",stdin);
	double x1,x2,y2,x,y,z,s,a1,a2,c;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&l[1],&l[3],&l[4],&l[2],&l[5],&l[6]))
	{

		c=(l[1]*l[1]+l[3]*l[3]-l[2]*l[2])/(2*l[1]*l[3]);
		x1=l[1];
		x2=l[3]*c,y2=l[3]*sqrt(1.0-c*c);
		s=x1*y2/2;

		x=( (l[4]*l[4]-l[5]*l[5])/x1+x1 )/2;
		a1=(x-x1)*(x-x1);
		a2=(x-x2)*(x-x2);
		y=( a2-a1+l[5]*l[5]-l[6]*l[6]+y2*y2 )/(2*y2);
		z=sqrt(l[4]*l[4]-x*x-y*y);

		printf("%.4lf\n",z*s/3);
	}
	return 0;
}