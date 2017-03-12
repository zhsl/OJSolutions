#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define x first
#define y second
#define pi acos(-1.0)
#define ull unsigned long long
#define ll long long
#define N 200010

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<vi> &a =matrix;
        vi ret(0);
        if(sz(matrix)==0)return ret;
        int n=sz(matrix), m=sz(matrix[0]);
        pii v, d(1,-1);
        int p=1;
        rep(i,0,m+n-1){
            if(i<m) v.x=0, v.y=i;
            else v.x=i-m+1, v.y=m-1;
            vi t;
            while(v.x<n && v.y>=0){
                t.pb(a[v.x][v.y]);
                v.x+=d.x;
                v.y+=d.y;
            }
            if(p&1) per(j,0,sz(t))ret.pb(t[j]);
            else rep(j,0,sz(t))ret.pb(t[j]);
            p^=1;
        }
        return ret;
    }
};



