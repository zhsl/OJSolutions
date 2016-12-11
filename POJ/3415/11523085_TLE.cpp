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
#include<set>
using namespace std;
//define
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
//typedef
typedef __int64 LL;
typedef unsigned __int64 ULL;
//const
const int N=200010;
const int INF=0x3f3f3f3f;
const int MOD=1000007,STA=8000010;
const LL LNF=1LL<<60;
const double EPS=1e-8;
const double OO=1e15;
//Daily Use ...
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
//

struct Node{
    int l,cnt;
}sta[N];

char s[N/2];
int num[N];
int sa[N],t1[N],t2[N],c[N],rank[N],height[N];
int n,m,len1,len2,K,ans;

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

void slove(int flag)
{
    int i,j,top=-1,cnt;
    for(i=2;i<=n;i++){
        if(height[i]<K){top=-1;continue;}
        if((sa[i-1]<len1)==flag){
            for(j=1;top>=0 && sta[top].l>=height[i];top--)j+=sta[top].cnt;
            sta[++top].l=height[i];
            sta[top].cnt=j;
        }
        if((sa[i]<len1)!=flag){
            for(j=0;j<=top;j++){
                ans+=(Min(sta[j].l,height[i])-K+1)*sta[j].cnt;
            }
        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    while(~scanf("%d",&K) && K)
    {
        scanf("%s",s);
        len1=strlen(s);
        for(i=0;i<len1;i++)num[i]=s[i]-'A'+1;
        scanf("%s",s);
        len2=strlen(s);
        num[i++]=99;
        for(j=0;j<len2;i++,j++)num[i]=s[j]-'A'+1;
        num[n=len1+len2+1]=0;
        m=100;

        build_sa(num,n+1,m);
        getHeight(num,n);
        /*
        for(i=1;i<=n;i++)
            printf(" %d %d\n",height[i],sa[i]<len1);
        putchar('\n');
        */
        ans=0;
        slove(1);
        slove(0);

        printf("%d\n",ans);
    }
    return 0;
}