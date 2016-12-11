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
    struct Node{
        Node(){mem(ch,0);val=0;}
        Node *ch[10];
        int val;
    };
    Node *head;

    void init(){head=new Node;}
    int insert(char *s,int v){
        int i,len=strlen(s),id;
        Node *p=head,*q;
        for(i=0;i<len;i++){
            id=s[i]-'0';
            if(!p->ch[id]){
                q=new Node;
                p->ch[id]=q;
            }
            p=p->ch[id];
            if(p->val)return 1;
        }
        p->val=v;
        for(i=0;i<10;i++)
            if(p->ch[i])return 1;
        return 0;
    }
  /*  int find(char *s){
        int i,len=strlen(s),id;
        Node *p=head;
        for(i=0;i<len;i++){
            id=s[i]-'0';
            if(!p->ch[id])return 0;
            p=p->ch[id];
        }
        for(i=0;i<10;i++)
            if(p->ch[i])return 1;
        return 0;
    }*/
    void free(Node *p){
        int i;
        for(i=0;i<10;i++)
            if(p->ch[i])free(p->ch[i]);
        delete p;
    }
};

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
        Trie trie;
        trie.init();
        scanf("%d",&n);
        while(n--){
            scanf("%s",s);
            if(trie.insert(s,1)){ok=0;break;}
        }
        if(n>1)while(n--)scanf("%s",s);

        printf("%s\n",ok?"YES":"NO");

        trie.free(trie.head);
    }
    return 0;
}