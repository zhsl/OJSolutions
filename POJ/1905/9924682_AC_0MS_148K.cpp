#include<stdio.h>
#include<math.h>
#define esp 1e-4
int main()
{
 //freopen("in.txt","r",stdin);
 double high,mid,low,r,L1,L2,lt,N,C;
 while(scanf("%lf%lf%lf",&L1,&N,&C)&&L1!=-1)
 {
  L2=(1+N*C)*L1;
  low=0 ,high=L1/2+1; 

  for(mid=(low+high)/2;high-low>esp;mid=(low+high)/2)
  {
   r=(L1*L1)/(4*mid)+mid;
   lt=2*r*atan(2*mid/L1);
   if(lt>L2)high=mid;
   else low=mid;
  }
  printf("%.3lf\n",mid);
 }
 return 0;
}