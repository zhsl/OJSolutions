#include<stdio.h>
#include<math.h>
const double PI=3.1415926;
int main()
{
//	freopen("in.txt","r",stdin);
	int k=1;
	double a,b,c,t,S,s,p,L,r,res,R;
	while(~scanf("%lf%lf%lf%lf",&a,&b,&c,&t) && a)
	{
		p=(a+b+c)/2;
		L=p*2;
		S=sqrt(p*(p-a)*(p-b)*(p-c));
		R=2*S/L;

		if(t/(2*PI)<=R)res=t*t/(4*PI);
		else if(t>=L)res=S;
		else {
			r=(L-t)/(L/R-2*PI);
			s=r*r*S/(R*R);
			res=S-s+PI*r*r;
		}
		printf("Case %d: %.2lf\n",k++,res);
	}
	return 0;
}