class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> l(nums.size());
        vector<int> r(nums.size());
        for(int i=0,k=0;i<nums.size();i++){
            l[i]=k;
            if(nums[i]==0)k=i+1;
        }
        for(int i=nums.size()-1,k=nums.size()-1;i>=0;i--){
            r[i]=k;
            if(nums[i]==0)k=i-1;
        }
        int ret=0;
        for(int i=0;i<nums.size();i++){
            if(r[i]-l[i]+1>ret)ret=r[i]-l[i]+1;
        }
        return ret;
    }
};
