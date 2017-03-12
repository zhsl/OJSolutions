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

    vector<int> nextGreaterElements(vector<int>& nums) {
        vi ret(sz(nums),-1);
        vi vis(sz(nums), 0);
        int ma=-0x3f3f3f3f,cnt_ma=0;
        for(int x: nums){
            if(x>ma)ma=x,cnt_ma=1;
            else if(x==ma)cnt_ma++;
        }
        stack<int> q;
        int cnt=0,i=0;
        while(cnt<sz(nums)-cnt_ma) {
            int w=i%sz(nums);
            if((q.empty() || nums[q.top()]>=nums[w]) && !vis[w]){
                q.push(w);
                i++;
            }
            else if(nums[q.top()]<nums[w]) {
                int t=q.top();q.pop();
                ret[t]=nums[w];
                vis[t]=1;
                cnt++;
            }
            else if(vis[w])i++;
        }
        return ret;
    }
};
