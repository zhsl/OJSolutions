class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ret=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            ret+=v.size() - (upper_bound(v.begin(),v.end(),nums[i])-v.begin());
            int t = (nums[i]+1)>>1;
            v.insert(lower_bound(v.begin(),v.end(),t),t);
        }
        return ret;
    }
};
