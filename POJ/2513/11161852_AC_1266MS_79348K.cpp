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
const int N=510000,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

struct Node{
    int u,v;
}e[N];
struct Trie{
    Trie(){mem(next,0);val=0;}
    Trie *next[26];
    int val;
};
int num[N],first[N],next[N],vis[N];
int cou,m;

void adde(int a,int b)
{
    e[m].u=a,e[m].v=b;
    next[m]=first[a],first[a]=m++;
    e[m].u=b,e[m].v=a;
    next[m]=first[b],first[b]=m++;
}

int bfs()
{
    int i,u,v,k=1;
    queue<int> q;
    q.push(1);
    mem(vis,0);
    vis[1]=1;
    while(!q.empty()){
        u=q.front();q.pop();
        for(i=first[u];i!=-1;i=next[i]){
            if(!vis[e[i].v]){
                vis[e[i].v]=1;
                q.push(e[i].v);
                k++;
            }
        }
    }
    return k==cou;
}

int build(Trie *rt,char *a)
{
    if(*a==0){
        if(rt->val)num[rt->val]++;
        else {
            rt->val=++cou;
            num[cou]++;
        }
        return rt->val;
    }
    int idx=*a-'a';
    if(!rt->next[idx])
        rt->next[idx]=new Trie;
    return build(rt->next[idx],a+1);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,ok,a,b;
    char s1[15],s2[15];
    Trie *head;
    head=new Trie;
    m=cou=0;
    mem(num,0);mem(first,-1);
    while(~scanf("%s%s",s1,s2)){
        a=build(head,s1);
        b=build(head,s2);
        adde(a,b);
    }
    ok=0;
    for(i=1;i<=cou;i++){
        if(num[i]&1)ok++;
        if(ok>2)break;
    }
    printf("%s\n",(!cou || ((ok==2 || ok==0) && bfs()))?"Possible":"Impossible");
    return 0;
}