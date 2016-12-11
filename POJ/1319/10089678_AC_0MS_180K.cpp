#include<stdio.h>
#include<math.h>
const double P=2*sqrt(3.0)/3;
int grid(double a,double b);
int skew(double a,double b);
int main()
{
//	freopen("in.txt","r",stdin);
	int g,s,s1,s2;
	double a,b;
	while(~scanf("%lf%lf",&a,&b))
	{
		g=grid(a,b);
		s1=skew(a,b),s2=skew(b,a);
		s=s1>s2?s1:s2;

		printf("%d %s\n",g>=s?g:s,g>=s?"grid":"skew");
	}
	return 0;
}

int grid(double a,double b)
{
	return (int)(floor(a)*floor(b));
}

int skew(double a,double b)
{
	int hn,l1,l2;
	hn=(int)floor((b-1)*P)+1;
	l1=(int)floor(a),l2=(int)floor(a+0.5)-1;
	return (hn+1)/2*l1+hn/2*l2;
}