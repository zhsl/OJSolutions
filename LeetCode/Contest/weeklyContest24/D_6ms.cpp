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
#define psi pair<string, int>

class Solution {
public:

    static int cmp(psi& a, psi& b){
        return a.y < b.y;
    }

    string findContestMatch(int n) {
        vector<psi> v[2];
        for(int i=1;i<=n;i++){
            string t = to_string(i);
            v[0].pb(mp(t, i));
        }
        int d=1;
        for(;n>>=1; d=!d){
            v[d].clear();
            sort(all(v[!d]), cmp);
            int len = sz(v[!d]);
            for(int i=0;i<(len>>1);i++){
                string t = "(" + v[!d][i].x + "," + v[!d][len-i-1].x + ")";
                v[d].pb( mp( t, min(v[!d][i].y, v[!d][len-i-1].y) ) );
            }
        }
        
        return v[!d][0].x;
    }
};
