#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAX=70;
int cmp(const void* a,const void *b);
int DFS(int k,int len,int t);
int ok(int cur);
int num[MAX],l[MAX*MAX],vis[MAX],m,minl,n,sum,now;
int main()
{
//    freopen("in.txt","r",stdin);
    int i,k,ok;
    while(scanf("%d",&n) && n)
    {
        minl=0x80000000;
        memset(vis,0,sizeof(vis));
        for(i=sum=0;i<n;i++){
            scanf("%d",&num[i]);
            sum+=num[i];
            if(num[i]>minl)minl=num[i];
        }
        qsort(num,n,sizeof(int),cmp);
        for(i=minl,k=0;i<=sum;i++){
            if(sum%i==0)l[k++]=i;
        }
                
        for(i=0;i<k;i++){
            now=l[i];
            m=sum/now;
            ok=DFS(0,0,0);
            if(ok)break;
        }
        
        printf("%d\n",now);
    }
    return 0;
}

int DFS(int k,int len,int t)
{
    if(k==m)return 1;
    for(int i=t;i<n;i++){
        if(!vis[i]){
            if(len+num[i]<now){
                vis[i]=1;
                if(DFS(k,len+num[i],t+1))return 1;
                vis[i]=0;
                if(!t)break;
            }
            if(len+num[i]==now){
                vis[i]=1;
                if(DFS(k+1,0,0))return 1;
                vis[i]=0;
                break;
            }
        }
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    return *(int*)b - *(int*)a;
}