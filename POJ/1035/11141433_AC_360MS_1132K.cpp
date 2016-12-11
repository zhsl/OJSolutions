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
#define put1(i,j,num) (li[i][0]|=(num<<(j<<1)))
#define get1(i,j) ((li[i][0]&(3<<(j<<1)))>>(j<<1))
#define put2(i,j,num) (li[i][1]|=(num<<j))
#define get2(i,j) ((li[i][1]&(1<<j))>>j)
const int N=10010,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

map<string,int> q;
char s[N][20];
int len[N];
int n;

int judge1(char *a,char *b,int len)
{
    int i,cou=0;
    for(i=0;i<len;i++){
        if(a[i]!=b[i])cou++;
        if(cou==2)return 0;
    }
    return 1;
}

int judge2(char *a,char *b,int len)
{
    int i,j,cou=0;
    for(i=j=0;i<len;i++,j++){
        if(b[j]!=a[i])j--,cou++;
        if(cou==2)return 0;
    }
    return 1;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,lent;
    char st[20];
    n=0;
    q.clear();
    while(++n){
        scanf("%s",s[n]);
        if(s[n][0]=='#'){n--;break;}
        q[s[n]]=1;
        len[n]=strlen(s[n]);
    }
    while(scanf("%s",st)){
        if(st[0]=='#')break;
        if(q[st])printf("%s is correct\n",st);
        else{
            lent=strlen(st);
            printf("%s:",st);
            for(i=1;i<=n;i++){
                if(lent==len[i] && judge1(s[i],st,lent))
                    printf(" %s",s[i]);
                else if(lent==len[i]+1 && judge2(st,s[i],lent))
                    printf(" %s",s[i]);
                else if(lent+1==len[i] && judge2(s[i],st,len[i]))
                    printf(" %s",s[i]);
            }
            putchar('\n');
        }
    }
    return 0;
}