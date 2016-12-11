#include<cstdio>
#include<string.h>
long long f[2][4100],a,b,n,m,k,j,p;
int main(){
   while(scanf("%d%d",&n,&m),memset(f,0,sizeof(f)),f[0][0]=p=1,a=n>m?n:m,b=n+m-a){
      while(a--)
       for(j=0;++j<=b;memset(f[p=1-p],0,sizeof(f[p])))
           for(k=(1<<b);--k+1;)
              if(k&1<<j-1)
                 f[p][k&~(1<<j-1)]+=f[1-p][k];
              else{
                   f[p][k|1<<j-1]+=f[1-p][k];
                   if(j<b&&!(k&1<<j))
                      f[p][k|1<<j]+=f[1-p][k];
              }
      printf("%lld\n",f[1-p][0]);
   }
}