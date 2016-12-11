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
const int N=10010,INF=0x3f3f3f3f,MOD=10000,STA=8000010;
const LL LNF=0x3f3f3f3f3f3f3f3f;
const double DNF=1e13;
//
void swap(int& a,int& b){int t=a;a=b;b=t;}
void swap(LL& a,LL& b){LL t=a;a=b;b=t;}
//

char s[N*100],te[N];
int next[N];
int T;

void getnext(char *s)
{
    int j=0,k=-1,len=strlen(s);
    next[0]=-1;
    while(j<len){
        if(k==-1 || s[j]==s[k])
            next[++j]=++k;
        else k=next[k];
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,lent,lens,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%s%s",te,s);
        lent=strlen(te);
        lens=strlen(s);
        getnext(te);

        for(i=j=0;i<lens;i++){
            while(s[i]!=te[j] && j!=-1)j=next[j];
            j++;
            if(j==lent){j=next[j];ans++;}
        }

        printf("%d\n",ans);
    }
    return 0;
}