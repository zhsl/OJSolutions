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
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=1000010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const double DNF=1e13;

char str[N<<1],s[N];
int p[N<<1];
int n,len;

void Manacher(char *str,int *p)
{
    int i,j,id,mx;
    id=1,mx=1;
    p[0]=p[1]=1;
    for(i=2;i<n;i++){
        p[i]=1;
        if(mx>i){
            p[i]=Min(p[(id<<1)-i],mx-i);
        }
        while(str[i+p[i]]==str[i-p[i]])p[i]++;
        if(i+p[i]>mx){
            id=i;
            mx=i+p[i];
        }
    }
}

void getstr(char *s)
{
    int i;
    str[0]='$';str[1]='#';
    for(i=0;i<len;i++){
        str[(i<<1)+2]=s[i];
        str[(i<<1)+3]='#';
    }
    str[n]=0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ans,ca=1;
    while(~scanf("%s",s))
    {
        len=strlen(s);
        if(len==3 && s[0]=='E' && s[1]=='N' && s[2]=='D')break;
        n=len*2+4;
        getstr(s);
        Manacher(str,p);

        ans=1;
        for(i=2;i<n;i++){
            ans=Max(ans,p[i]-1);
        }

        printf("Case %d: %d\n",ca++,ans);
    }
    return 0;
}