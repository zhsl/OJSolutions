#include<stdio.h>
__int64 C(__int64 a,__int64 b);
__int64 sum(__int64 tar);
__int64 cij[35],flag;
int main()
{
//	freopen("in.txt","r",stdin);
	__int64 i,s,d;
	for(i=1;i<=32;i++)cij[i]=C(i-1,(i+1)/2);

	while(~scanf("%I64d%I64d",&s,&d)){
		flag=0;
		printf("%I64d\n",sum(d)-sum(s));
	}

	return 0;
}

__int64 sum(__int64 tar)
{
	__int64 i,len,zero,s=0,k;
	for(i=31;!(tar&(1<<i));i--);
	len=i;
	for(i=1;i<=len;i++)s+=cij[i];
	for(i=len-1,zero=0;i>=0;i--){
		if(tar&(1<<i)){
			k=len/2-zero;
			s+=C(i,k>0?k:0);
		}
		else zero++;
	}
	if(!flag){
		for(i=len,zero=0;i>=0;i--)if(!(tar&(1<<i)))zero++;
		if(len-zero+1<=zero)s++;
	}
	flag++;
	return s;
}

__int64 C(__int64 a,__int64 b)
{
	__int64 i,j,s1,s2,s,ta,ti;
	b=a-b;
	for(i=0,s=0;i<=b;i++){
		for(j=0,ta=a,ti=i,s1=s2=1;j<i;j++){
			s1*=ta,ta--;
			s2*=ti,ti--;
		}
		s+=s1/s2;
	}
	return s;
}