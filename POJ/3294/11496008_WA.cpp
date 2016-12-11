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
const int N=101010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;
//
void swap(int& a,int& b){int t=a;a=b;b=t;}
void swap(LL& a,LL& b){LL t=a;a=b;b=t;}
//

int num[N]={1,1,2,1,1,1,1,2,0};
int sa[N],t1[N],t2[N],c[N],rank[N],height[N],vis[N],ma[N];
int n,m,T;

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
    int i,j,mid,ok,ret,k,cnt;
    mem(vis,0);k=1;
    while(l<=r){
        mid=(l+r)>>1;
        cnt=1;ok=0;
        vis[ma[sa[1]]]=k;
        for(i=2;i<=n;i++){
            if(height[i]>=mid){
                if(vis[ma[sa[i]]]!=k)vis[ma[sa[i]]]=k,cnt++;
            }
            else {
                if(cnt>T/2){ok=1;break;}
                k++;cnt=1;
                vis[ma[sa[i]]]=k;
            }
        }
        k++;
        if(cnt>T/2)ok=1;
      //  printf("%d %d %d\n",mid,ok,cnt);
        if(ok)ret=mid,l=mid+1;
        else r=mid-1;
    }
    return ret;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,cnt,ans,k,t;
    char s[N];
    while(~scanf("%d",&T) && T)
    {
        n=0;cnt=130;
        for(i=0;i<T;i++){
            scanf("%s",s);
            for(j=0;s[j];j++){
                ma[n]=i;
                num[n++]=s[j]-'a'+1;
            }
            ma[n]=i;
            num[n++]=cnt++;
        }
        num[n]=0;
        m=cnt;
        build_sa(num,n+1,m);
        getHeight(num,n);

        ans=binary(0,101);
        if(ans){
            if(T==1){
                printf("%s\n\n",s);
                continue;
            }
         //   printf(" %d\n",ans);
            mem(vis,0);
            k=1;cnt=1;
            vis[ma[sa[1]]]=1;
            for(i=2;i<=n;i++){
                if(height[i]>=ans){
                    if(vis[ma[sa[i]]]!=k)vis[ma[sa[i]]]=k,cnt++;
                }
                else {
                    if(cnt>T/2){
                        for(j=sa[i-1],t=ans;t--;j++)
                            printf("%c",num[j]+'a'-1);
                        putchar('\n');
                    }
                    k++;cnt=1;
                    vis[ma[sa[i]]]=k;
                }
            }
            if(cnt>T/2){
                for(j=sa[i-1],t=ans;t--;j++)
                    printf("%c",num[j]+'a'-1);
                putchar('\n');
            }
        }
        else printf("?\n");
        putchar('\n');
    }
    return 0;
}