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

struct Trie {
    int ch[1<<16][10];
    int val[1<<16];
    int sz;

    void init(){sz=1;mem(ch[0],0);}
    int insert(char *s,int v){
        int i,len=strlen(s),id,u=0;
        for(i=0;i<len;i++){
            id=s[i]-'0';
            if(!ch[u][id]){
                mem(ch[sz],0);
                val[sz]=0;
                ch[u][id]=sz++;
            }
            u=ch[u][id];
            if(val[u])return 1;
        }
        val[u]=v;
        for(i=0;i<10;i++)
            if(ch[u][i])return 1;
        return 0;
    }
 /*   int find(char *s){
        int i,len=strlen(s),id,u=0;
        for(i=0;i<len;i++){
            id=s[i]-'0';
            if(!ch[u][id])return 0;
            u=ch[u][id];
        }
        for(i=0;i<10;i++)
            if(ch[u][id])return 1;
        return 0;
    }*/
}trie;

int T,n;
char s[12];

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ok;
    scanf("%d",&T);
    while(T--)
    {
        ok=1;
        trie.init();
        scanf("%d",&n);
        while(n--){
            scanf("%s",s);
            if(trie.insert(s,1)){ok=0;break;}
        }
        if(n>1)while(n--)scanf("%s",s);

        printf("%s\n",ok?"YES":"NO");
    }
    return 0;
}


