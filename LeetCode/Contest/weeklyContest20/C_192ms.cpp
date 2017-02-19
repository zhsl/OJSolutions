class Solution {
public:

    static const int N=50010;
    int INF=0x3f3f3f3f;
    int w[N<<1];
    
    int findMaxLength(vector<int>& nums) {
        int pre = 0;
        int ans=0;
        memset(w,INF,sizeof(w));
        w[0+N]=0;
        
        for(int i=0;i<nums.size();i++){
            pre += nums[i]?1:-1;
            if(w[pre+N]==INF){
                w[pre+N]=i+1;
            }
            else if(i+1 - w[pre+N] > ans) {
                ans = i+1 - w[pre+N];
            }
        }
        return ans;
    }
};
