#include<stdio.h>
int f(int m,int n);
int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        printf("%d\n",f(m,n));
    }
    return 0;
}

int f(int m,int n)
{
    if(m<0)return 0;
    if(!m || n==1)return 1;
    return f(m-n,n)+f(m,n-1);
}