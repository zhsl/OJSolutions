#include <functional>
#include <algorithm>
#include <iostream>
//#include <ext/rope>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
//using namespace __gnu_cxx;
//define
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
//typedef
typedef long long LL;
typedef unsigned long long ULL;
//const
const int N=73;
const int INF=0x3f3f3f3f;
const int MOD=100000,STA=8000010;
const LL LNF=1LL<<60;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//Daily Use ...
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

int A[N][N];//增广矩阵
int B[N];//解集
bool free_x[N];//标记是否是不确定的变元
int T,n,m,k,p;

//
void Debug(int equ,int var)
{
    int i, j;
    for(i=0;i<equ;i++){
        for(j=0;j<=var;j++)
            printf("%4d",A[i][j]);
        putchar('\n');
    }
    putchar('\n');
}
//

void extgcd(int a,int b,int &d,int &x,int &y)
{
    if(!b){d=a;x=1;y=0;}
    else {extgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

inline int gcd(int a,int b)
{
    int t;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

inline int lcm(int a,int b)
{
    return a/gcd(a,b)*b;//先除后乘防溢出
}

// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
//-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int Gauss(int equ,int var)
{
    int i,j,k;
    int max_r; // 当前这列绝对值最大的行.
    int col; //当前处理的列
    int ta,tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;

    for(int i=0;i<=var;i++)
    {
        B[i]=0;
        free_x[i]=true;
    }
    //转换为阶梯阵.
    col=0; // 当前处理的列
    for(k = 0;k < equ && col < var;k++,col++)
    {// 枚举当前处理的行.
// 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r=k;
        for(i=k+1;i<equ;i++)
        {
            if(abs(A[i][col])>abs(A[max_r][col])) max_r=i;
        }
        if(max_r!=k)
        {// 与第k行交换.
            for(j=k;j<var+1;j++) swap(A[k][j],A[max_r][j]);
        }
        if(A[k][col]==0)
        {// 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)    //  i=0高斯约当消元,才能在多解的情况下判断变元是否确定
        {// 枚举要删去的行.
            if(A[i][col]!=0 && i!=k)
            {
                LCM = lcm(abs(A[i][col]),abs(A[k][col]));
                ta = LCM/abs(A[i][col]);
                tb = LCM/abs(A[k][col]);
                if(A[i][col]*A[k][col]<0)tb=-tb;//异号的情况是相加
                for(j=0;j<=var;j++)
                {
                    A[i][j] = (A[i][j]*ta - A[k][j]*tb)%p;
                }
            }
        }
    }

  //  Debug(equ,var);

    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    /*
    for (i = k; i < equ; i++)
    {
        if (A[i][col] != 0) return -1;
    }
    // 对于无穷解来说，如果要判断哪些是自由变元，那么初等行变换中的交换就会影响，则要记录交换.
    // 2. 无穷解的情况: 在var * (var + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    // 且出现的行数即为自由变元的个数.
    if (k < var)return 1;
    {
        // 首先，自由变元有var - k个，即不确定的变元至少有var - k个.
        for (i = k - 1; i >= 0; i--)
        {
            // 第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第equ行.
            // 同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.
            free_x_num = 0; // 用于判断该行中的不确定的变元的个数，如果超过1个，则无法求解，它们仍然为不确定的变元.
            for (j = 0; j < var; j++)
            {
                if (A[i][j] != 0 && free_x[j]) free_x_num++, free_index = j;
            }
            if (free_x_num > 1) continue; // 无法求解出确定的变元.
            // 说明就只有一个不确定的变元free_index，那么可以求解出该变元，且该变元是确定的.
            temp = A[i][var];
            for (j = 0; j < var; j++)
            {
                if (A[i][j] != 0 && j != free_index) temp -= A[i][j] * x[j];
            }
            x[free_index] = temp / A[i][free_index]; // 求出该变元.
            free_x[free_index] = 0; // 该变元是确定的.
        }
        return var - k; // 自由变元有var - k个.
    }*/
    // 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    for (i = var - 1; i >= 0; i--)
    {
        temp = A[i][var];
        for (j = i + 1; j < var; j++)
        {
            if (A[i][j] != 0) temp = (temp-(A[i][j] * B[j]))%p;
        }
   //     if (temp % A[i][i] != 0) return -2; // 说明有浮点数解，但无整数解.
        int x,y,d;
        extgcd(A[i][i],p,d,x,y);
        B[i]=((x*(temp/d))%p+p)%p;
     //   x[i] = (temp / A[i][i])%p;
    }
    return 0;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j,t;
    char s[N];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s",&p,s);
        n=strlen(s);
        for(i=0;i<n;i++){
            t=1;
            for(j=0;j<n;j++){
                A[i][j]=t;
                t=(t*(i+1))%p;
            }
            A[i][j]=s[i]=='*'?0:s[i]-'a'+1;
        }

        Gauss(n,n);
     //   Debug(n,n);

        printf("%d",B[0]);
        for(i=1;i<n;i++)
            printf(" %d",B[i]);
        putchar('\n');
    }
    return 0;
}