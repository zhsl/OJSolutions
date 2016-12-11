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
#include<set>
using namespace std;
//define
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
//typedef
typedef __int64 LL;
typedef unsigned __int64 ULL;
//const
const int N=101;
const int INF=0x3f3f3f3f;
const int MOD=100000,STA=8000010;
const LL LNF=1LL<<60;
const double EPS=1e-8;
const double OO=1e15;
//Daily Use ...
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

int idx[N];
int ch[N][4];
int val[N],f[N],sta[N];
int sz,n,m;
int size;

struct Matrix{
    LL ma[N][N];
    Matrix friend operator * (const Matrix a,const Matrix b){
        Matrix ret;
        mem(ret.ma,0);
        int i,j,k;
        for(k=0;k<size;k++)
            for(i=0;i<size;i++)
                for(j=0;j<size;j++)
                    ret.ma[i][j]=(ret.ma[i][j]+a.ma[i][k]*b.ma[k][j])%MOD;
        return ret;
    }
}ans,mta;

void mutilpow(LL k)
{
    int i,j;
    mem(ans.ma,0);
    for(i=0;i<size;i++)
        ans.ma[i][i]=1;
    for(;k;k>>=1){
        if(k&1)ans=ans*mta;
        mta=mta*mta;
    }
}

void init(){sz=1;mem(ch[0],0);}

void insert(char *s,int v){
    int i,len=strlen(s),id,u=0;
    for(i=0;i<len;i++){
        id=idx[s[i]];
        if(!ch[u][id]){
            mem(ch[sz],0);
            val[sz]=0;
            ch[u][id]=sz++;
        }
        u=ch[u][id];
    }
    val[u]=v;
}

void getFail()
{
    int u,v,r,c;
    queue<int> q;
    mem(mta.ma,0);
    f[0]=0;
    sta[0]=size++;
    for(c=0;c<4;c++){
        u=ch[0][c];
        if(u){f[u]=0;q.push(u);}
        if(u && !val[u]){
            sta[u]=size++;
            mta.ma[0][sta[u]]++;
        }
        else if(!u){
            mta.ma[0][0]++;
        }
    }
    while(!q.empty()){
        r=q.front();q.pop();
        for(c=0;c<4;c++){
            u=ch[r][c];
            if(!u){ch[r][c]=ch[f[r]][c];}
            else {
                q.push(u);
                v=f[r];
                while(v && !ch[v][c])v=f[v];
                f[u]=ch[v][c];
            }

            if(sta[r]==-1)continue;
            if(u){
                if(val[u] || sta[f[u]]==-1)continue;
                sta[u]=size++;
                mta.ma[sta[r]][sta[u]]++;
            }
            else {
                v=ch[r][c];
                if(sta[v]==-1)continue;
                mta.ma[sta[r]][sta[v]]++;
            }

        }
    }
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    LL sum;
    char s[20];
    idx['A']=0;idx['C']=1;idx['T']=2,idx['G']=3;
    while(~scanf("%d%d",&m,&n))
    {
        init();
        for(i=0;i<m;i++){
            scanf("%s",s);
            insert(s,1);
        }

        mem(sta,-1);
        size=0;
        getFail();
        /*
        printf(" %d\n",size);
        for(i=0;i<size;i++){
            for(j=0;j<size;j++)
                printf("%3d",mta.ma[i][j]);
            putchar('\n');
        }
        */
        mutilpow(n);
        for(i=sum=0;i<size;i++){
            sum+=ans.ma[0][i];
        }

        printf("%I64d\n",sum%MOD);
    }
    return 0;
}