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
const int N=4010,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

char s[N][210],ans[210];
int next[210],w[N];
int n,m;

void getnext(char *a,int len)
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<len){
        if(k==-1 || a[k]==a[j])
            next[++j]=++k;
        else k=next[k];
    }
}

int cmp(char *a,int len)
{
    int i,j,ok,k;
    for(i=1;i<n;i++){
        for(j=ok=k=0;j<w[i];j++){
            while(k>0 && s[i][j]!=a[k])k=next[k];
            if(s[i][j]==a[k])k++;
            if(k==len){ok=1;break;}
        }
        if(!ok)return 0;
    }
    return 1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,maxlen,ok,t,lens,minlen;
    while(~scanf("%d",&n) && n)
    {
        minlen=INF;
        maxlen=-INF;
        for(i=0;i<n;i++){
            scanf("%s",s[i]);
            w[i]=strlen(s[i]);
            if(w[i]<minlen)minlen=w[i];
        }
        for(i=0;i<w[0];i++){
            for(j=i+1;j<=w[0];j++){
                lens=j-i;
                if(lens<maxlen && lens<=minlen)continue;
                getnext(*s+i,lens);
                if(cmp(*s+i,lens)){
                    t=s[0][j];
                    s[0][j]='\0';
                    if(lens>maxlen){
                        maxlen=lens;
                        strcpy(ans,*s+i);
                    }
                    else if(strcmp(ans,*s+i)>0)
                        strcpy(ans,*s+i);
                    s[0][j]=t;
                }
            }
        }

        printf("%s\n",maxlen>0?ans:"IDENTITY LOST");
    }
    return 0;
}