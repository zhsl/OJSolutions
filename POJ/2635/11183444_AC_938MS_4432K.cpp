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
using namespace std;
#define LL __int64
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=110,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

char s[N];
int num[N],pri[M+10],isp[M+10];
int p,k,hav;

inline int yu(int m)
{
    int i;
    LL t;
    for(i=k-1,t=0;i>=0;i--){
        t=num[i]+t*1000000;
        t%=m;
    }
    return t;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,len,ok;
    len=(int)sqrt(M*1.0);
    for(i=2;i<=len;i++)
        if(!isp[i])
            for(j=i+i;j<=M;j+=i)isp[j]=1;
    for(i=2,hav=0;i<=M;i++)
        if(!isp[i])pri[hav++]=i;
    while(~scanf("%s%d",s,&p) && p)
    {
        ok=k=0;
        len=strlen(s);
        for(i=len-1;i>=0;k++)
            for(num[k]=0,j=1;j<1000000 && i>=0;j*=10,i--)
                num[k]+=(s[i]-'0')*j;
        for(i=0;pri[i]<p && i<hav;i++)
            if(!yu(pri[i])){ok=1;break;};

        if(ok)printf("BAD %d\n",pri[i]);
        else printf("GOOD\n");
    }
    return 0;
}