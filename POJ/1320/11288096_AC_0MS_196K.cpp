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
#define pdi pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=100000010,INF=0x3f3f3f3f,MOD=1999997;
const double DNF=100000000000;

int n;

int main()
{
 //   freopen("in.txt","w",stdout);
 /*   LL i,k,c;
    double j;
    for(i=2,k=0;k<10;i++){
        j=sqrt(8*i*i+1);
        if(j==floor(j)){
            c=(-(2*i+1)+(int)j);
            if(!(c&1) && c>0){
                k++;
                printf("%10I64d%10I64d\n",i,c/2+i);
            }
        }
    }*/
    cout<<
"         6         8\n"
"        35        49\n"
"       204       288\n"
"      1189      1681\n"
"      6930      9800\n"
"     40391     57121\n"
"    235416    332928\n"
"   1372105   1940449\n"
"   7997214  11309768\n"
"  46611179  65918161\n";
    return 0;
}