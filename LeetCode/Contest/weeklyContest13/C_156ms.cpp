class Solution {
public:

    bool dfs(vector<int>& nums, vector<int>& val, int len, int he, int tar){
        if(he==(tar<<2) && len==nums.size()){
            return true;
        }
        else if(len==nums.size())return false;
        bool ret=false;
        for(int i=0;i<4;i++){
            if(nums[len]+val[i]<=tar){
                val[i]+=nums[len];
                if(dfs(nums,val,len+1,he+nums[len],tar)){
                    ret= true;
                    break;
                }
                val[i]-=nums[len];
            }
        }
        return ret;
    }

    static int cmp(int a, int b){
        return a>b;
    }

    bool makesquare(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if((sum&3) || !sum)return false;
        int tar=sum/4;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>tar)return false;
        }
        
        sort(nums.begin(),nums.end(), cmp);
        vector<int> val(4,0);
        int he=0;
        return dfs(nums, val, 0, he, sum/4);
    }
};


