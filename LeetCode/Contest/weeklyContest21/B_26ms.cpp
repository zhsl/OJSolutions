class Solution {
public:
    
    int pre[10010];

    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2){
            return false;
        }
        pre[0]=0;
        for(int i=0;i<nums.size();i++){
            pre[i+1]=pre[i]+nums[i];
        }
        for(int i=2;i<=nums.size();i++){
            if(pre[i]-pre[i-2]==0)return true;
        }
        if(k==0){
            return false;
        }
        if(k<0)k=-k;
        
        for(int i=2;i<=nums.size();i++){
            for(int j=(pre[i]-pre[i-2])/k;1;j++){
                int tar=pre[i]-j*k;
                if(tar<0)break;
                int w = lower_bound(pre, pre+i+1, tar)- pre;
                if(i-w>=2 && pre[w]==tar){
                    return true;
                }
            }
        }
        return false;
    }
};
