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
#define LL long long
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
const int N=20010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;
//
void swap(int& a,int& b){int t=a;a=b;b=t;}
void swap(LL& a,LL& b){LL t=a;a=b;b=t;}
//

int num[N]={1,1,2,1,1,1,1,2,0};
int sa[N],t1[N],t2[N],c[N],rank[N],height[N];
int n,m;

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
    int i,j,mid,low,hig,ok,ret;
    while(l<=r){
        mid=(l+r)>>1;
        ok=0;
        low=hig=sa[0];
        for(i=2;i<=n;i++){
            if(height[i]>=mid){
                if(sa[i]<low)low=sa[i];
                else if(sa[i]>hig)hig=sa[i];
            }
            else {
                if(hig-low>=mid){ok=1;break;}
                low=hig=sa[i];
            }
        }
        if(hig-low>=mid)ok=1;
        if(ok)ret=mid,l=mid+1;
        else r=mid-1;
    }
    if(ret>=4)return ret+1;
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,l,r;
    while(~scanf("%d",&n) && n)
    {
        scanf("%d",&l);
        for(i=1;i<n;i++){
            scanf("%d",&r);
            num[i-1]=r-l+88;
            l=r;
        }
        num[--n]=0;
        m=176;
        build_sa(num,n+1,m);
        getHeight(num,n);

        printf("%d\n",binary(0,n));
    }
    return 0;
}