#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
const int N=200010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
//const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;
//
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
void swap(int& a,int& b){int t=a;a=b;b=t;}
void swap(LL& a,LL& b){LL t=a;a=b;b=t;}
//

char s[N/2];
int num[N];
int sa[N],t1[N],t2[N],c[N],rank[N],height[N];
int n,m,len1,len2;

void build_sa(int s[],int n,int m)
{
    int i,k,p,*x=t1,*y=t2;
    //第一轮基数排序
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(k=1;k<=n;k<<=1){
        p=0;
        //直接利用sa数组排序第二关键字
        for(i=n-k;i<n;i++)y[p++]=i;
        for(i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
        //基数排序第一关键字
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        //根据sa和x数组计算新的x数组
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        if(p>=n)break;   //已经排好序，直接退出
        m=p;     //下次基数排序的最大值
    }
}

void getHeight(int s[],int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;i++){
        if(k)k--;
        j=sa[rank[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rank[i]]=k;
    }
}

int binary(int l,int r)
{
    int i,j,mid,ok1,ok2,ret;
    while(l<r){
        mid=(l+r)>>1;
        ok1=ok2=0;
        if(sa[1]<len1)ok1=1;
        else if(sa[1]>len1)ok2=1;
        for(i=2;i<=n;i++){
            if(height[i]>=mid){
                if(sa[i]<len1)ok1=1;
                else if(sa[i]>len1)ok2=1;
            }
            else {
                if(ok1 && ok2)break;
                ok1=ok2=0;
                if(sa[i]<len1)ok1=1;
                else if(sa[i]>len1)ok2=1;
            }
        }
        if(ok1 && ok2)ret=mid,l=mid+1;
        else r=mid;
    }
    return ret;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%s",s) && s[0]!='#')
    {
        len1=strlen(s);
        for(i=0;i<len1;i++)num[i]=s[i]-'a'+1;
        num[len1]=27;
        scanf("%s",s);
        len2=strlen(s);
        n=len1+len2+1;
        for(i++,j=0;i<n;i++,j++)num[i]=s[j]-'a'+1;
        num[n]=0;
        m=28;
        build_sa(num,n+1,m);
        getHeight(num,n);

        printf("%d\n",binary(0,Min(len1,len2))+1);
    }
    return 0;
}