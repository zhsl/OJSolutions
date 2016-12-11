#include<stdio.h>
const int MAX=70;
int DFS(int cur);
int ok(int cur);
int num[MAX],l[MAX*MAX],A[MAX],m,minl,n,sum,now;
int main()
{
//    freopen("in.txt","r",stdin);
    int i,j,k,ok;
    while(scanf("%d",&n) && n)
    {
        minl=0x80000000;
        for(i=sum=0;i<n;i++){
            scanf("%d",&num[i]);
            sum+=num[i];
            if(num[i]>minl)minl=num[i];
        }
        for(i=minl,k=0;i<=sum;i++){
            if(sum%i==0)l[k++]=i;
        }
                
        for(i=0;i<k;i++){
            now=l[i];
            m=sum/now;
            ok=DFS(0);
            if(ok)break;
        }
        
        printf("%d\n",now);
    }
//    getch();
//    system("pause");
    return 0;
}

int DFS(int cur)
{
    int i,t=ok(cur);
    if(cur==n &&t==m)return 1;
    if(t==-1)return 0;
    for(i=1;i<=m;i++){
        A[cur]=i;
        if(DFS(cur+1))return 1;
    }
    return 0;
}

int ok(int cur)
{
    int i,k=0,sum[MAX]={0},t,ok=1;
    for(i=0;i<cur;i++){
        t=A[i];
        sum[t]+=num[i];
        if(sum[t]>now){ok=0;break;};
        if(sum[t]==now)k++;
    }
    if(ok)return k;
    else return -1;
}