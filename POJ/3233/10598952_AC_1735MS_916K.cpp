#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
#define LL __int64
const int MAX=32,INF=1000000000,MOD=2008;
struct Matrix
{
	int a[MAX][MAX];
};
Matrix Matrix_add(Matrix &a,Matrix &b);
Matrix Matrix_mutil(Matrix &a,Matrix &b);
Matrix power(Matrix a,int n);
Matrix slove(int n);
int n,k,m;
Matrix ma,E;
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	for(i=0;i<MAX;i++)
		E.a[i][i]=1;
	scanf("%d%d%d",&n,&k,&m);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&ma.a[i][j]);
			ma.a[i][j]%=m;
		}
	ma=slove(k);

	for(i=0;i<n;i++){
		printf("%d",ma.a[i][0]);
		for(j=1;j<n;j++)
			printf(" %d",ma.a[i][j]);
		putchar('\n');
	}
	return 0;
}

Matrix Matrix_add(Matrix &a,Matrix &b)
{
	int i,j;
	Matrix t;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			t.a[i][j]=(a.a[i][j]+b.a[i][j])%m;
	return t;
}

Matrix Matrix_mutil(Matrix &a,Matrix &b)
{
	int i,j,k;
	Matrix t;
	memset(t.a,0,sizeof(t.a));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				t.a[i][j]=(t.a[i][j]+a.a[i][k]*b.a[k][j])%m;
	return t;
}

Matrix power(Matrix a,int p)
{
	int i,q;
	Matrix t;
	memset(t.a,0,sizeof(t.a));
	for(i=0;i<n;i++)
		t.a[i][i]=1;
	for(q=p;q;q>>=1){
		if(q&1)t=Matrix_mutil(t,a);
		a=Matrix_mutil(a,a);
	}
	return t;
}

Matrix slove(int n)
{
	Matrix t1,t2;
	if(n==1)return ma;
	if(n&1){
		t1=slove(n-1);
		t2=power(ma,n);
		return Matrix_add(t1,t2);
	}
	else {
		t1=power(ma,n>>1);
		t2=Matrix_add(E,t1);
		t1=slove(n>>1);
		return Matrix_mutil(t1,t2);
	}
}