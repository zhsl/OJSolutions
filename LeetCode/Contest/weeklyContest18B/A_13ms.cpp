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
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vi &a =findNums, &b=nums;
        vi ret(sz(a), -1);
        rep(i,0,sz(a)) {
            rep(j,0,sz(b)){
                if(a[i]==b[j]){
                    rep(k,j+1,sz(b)) {
                        if(b[k]>a[i]){
                            ret[i]=b[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ret;
    }
};
