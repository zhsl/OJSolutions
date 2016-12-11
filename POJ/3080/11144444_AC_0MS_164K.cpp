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
const int N=70,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

char s[12][N],ans[N];
int next[N];
int T,n,m,len;

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
        for(j=ok=k=0;j<m;j++){
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
    int i,j,maxlen,ok,t;
    scanf("%d",&T);
    while(T--)
    {
        m=60;
        maxlen=-INF;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        for(i=0;i<m;i++){
            for(j=i+3;j<=m;j++){
                len=j-i;
                if(len<maxlen)continue;
                getnext(*s+i,len);
                if(cmp(*s+i,len)){
                    t=s[0][j];
                    s[0][j]='\0';
                    if(len>maxlen){
                        maxlen=len;
                        strcpy(ans,*s+i);
                    }
                    else if(strcmp(ans,*s+i)>0)
                        strcpy(ans,*s+i);
                    s[0][j]=t;
                }
            }
        }

        printf("%s\n",maxlen>2?ans:"no significant commonalities");
    }
    return 0;
}