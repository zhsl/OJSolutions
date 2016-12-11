#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL __int64
const int MAX=100000,INF=2000000010;
int cmp(const void *a,const void *b){return *(int*)a - *(int*)b;}
int ans[MAX];
int k,n;
LL two[40],thr[40],f[40],s[40];
int main()
{
//    freopen("in.txt","r",stdin);
    int i,j,p,q;
    LL a,b,c,d;
    k=0;
    for(i=0;i<MAX;i++)ans[i]=INF;
    for(i=1,two[0]=1;i<32;i++)two[i]=two[i-1]*2;
    for(i=1,thr[0]=1;i<21;i++)thr[i]=thr[i-1]*3;
    for(i=1,f[0]=1;i<15;i++)f[i]=f[i-1]*5;
    for(i=1,s[0]=1;i<12;i++)s[i]=s[i-1]*7;

    for(i=0;i<=31;i++){
        a=two[i];
        if(a>INF)continue;
        for(j=0;j<=20;j++){
            b=thr[j];
            if(a*b>INF)break;
            for(p=0;p<=14;p++){
                c=f[p];
                if(a*b*c>INF)break;
                for(q=0;q<=11;q++){
                    d=s[q];
                    if(a*b*c*d>INF)break;
                    ans[k++]=(int)(a*b*c*d);
                }
            }
        }
    }
    qsort(ans,k,sizeof(int),cmp);
    while(scanf("%d",&n) && n)
    {
        if(n%10==1 && n%100!=11)
            printf("The %dst humble number is %d.\n",n,ans[n-1]);
        else if(n%10==2 && n%100!=12)
            printf("The %dnd humble number is %d.\n",n,ans[n-1]);
        else if(n%10==3 && n%100!=13)
            printf("The %drd humble number is %d.\n",n,ans[n-1]);
        else 
            printf("The %dth humble number is %d.\n",n,ans[n-1]);
    }
    return 0;
}