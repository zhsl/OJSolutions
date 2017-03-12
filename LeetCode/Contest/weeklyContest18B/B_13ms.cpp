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

    static int cmp(pii &a, pii &b){
        return a.x > b.x;
    }

    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pii> a(sz(nums));
        rep(i,0,sz(nums)) {
            a[i]=mp(nums[i],i);
        }
        sort(all(a), cmp);
        
        vector<string> ret(sz(nums));
        
        int i=0;
        if(i<sz(a))ret[a[i].y]="Gold Medal",i++;
        if(i<sz(a))ret[a[i].y]="Silver Medal",i++;
        if(i<sz(a))ret[a[i].y]="Bronze Medal",i++;
        for(;i<sz(a);i++){
            ret[a[i].y]=to_string(i+1);
        }
        return ret;
    }
};
