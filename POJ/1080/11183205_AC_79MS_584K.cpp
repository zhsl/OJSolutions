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
const int N=310,INF=0x3f3f3f3f,MOD=1999997;
const LL LLNF=0x3f3f3f3f3f3f3f3fLL;

char s1[N],s2[N];
int f[N][N],ma[N][N];
int a,b,T,len1,len2;

void get(char *s,int a,int b)
{
    int i;
    char st[N];
    for(i=0;i<a;i++)st[i]=s[i];
    for(i=0;i<b;i++)s[i]=0;
    for(;i<a+b;i++)s[i]=st[i-b];
    for(;i<2*a+b;i++)s[i]=0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,k,t;
    ma['A']['A']=5,ma['A']['C']=-1,ma['A']['G']=-2,ma['A']['T']=-1,ma['A'][0]=-3;
    ma['C']['A']=-1,ma['C']['C']=5,ma['C']['G']=-3,ma['C']['T']=-2,ma['C'][0]=-4;
    ma['G']['A']=-2,ma['G']['C']=-3,ma['G']['G']=5,ma['G']['T']=-2,ma['G'][0]=-2;
    ma['T']['A']=-1,ma['T']['C']=-2,ma['T']['G']=-2,ma['T']['T']=5,ma['T'][0]=-1;
    ma[0]['A']=-3,ma[0]['C']=-4,ma[0]['G']=-2,ma[0]['T']=-1,ma[0][0]=0;
    scanf("%d",&T);
    while(T--){
        mem(f,-INF);
        scanf("%d%s%d%s",&a,s1,&b,s2);
        len1=a+2*b;len2=b+2*a;
        get(s1,a,b);
        get(s2,b,a);

        for(i=0;i<a;i++)f[0][i]=0;
        for(t=0;i<a+b;i++){f[0][i]=ma[s1[0]][s2[i]]+t;t+=ma[0][s2[i]];}
        for(t=f[0][i-1];i<len2;i++)f[0][i]=t;
        for(i=0;i<len1-1;i++){
            for(j=0;j<len2;j++){
                f[i+1][j]=Max(f[i+1][j],f[i][j]+ma[s1[i+1]][0]);
                for(t=0,k=j+1;k<len2;k++){
                    f[i+1][k]=Max(f[i+1][k],f[i][j]+ma[s1[i+1]][s2[k]]+t);
                    t+=ma[0][s2[k]];
                }
            }
        }

        printf("%d\n",f[len1-1][len2-1]);
    }
    return 0;
}