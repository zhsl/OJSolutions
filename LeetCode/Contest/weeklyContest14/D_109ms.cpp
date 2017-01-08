class Solution {
public:
    void adjust(multiset<int>& low, multiset<int>& upp) {
        while(low.size()<upp.size()) {
            int u=*(--upp.end());
            upp.erase(--upp.end());
            low.insert(u);
        }
        while(low.size()-upp.size()>=2) {
            int l=*(low.begin());
            low.erase(low.begin());
            upp.insert(l);
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> low;
        multiset<int> upp;
        vector<double> ret(nums.size()-k+1);
        if(k==1){
            for(int i=0;i<nums.size();i++) ret[i]=nums[i];
            return ret;
        }
        for(int i=0;i<k;i++)low.insert(nums[i]);
        adjust(low, upp);
        for(int i=k;i<nums.size();i++){
            int l=*(low.begin());
            int u=*(--upp.end());
            ret[i-k]=(k&1)?(double)l:((double)l + u) / 2;
            if(nums[i-k]>=l) low.erase(low.find(nums[i-k]));
            else upp.erase(upp.find(nums[i-k]));
            if(low.size() && nums[i]>=l)low.insert(nums[i]);
            else upp.insert(nums[i]);
            adjust(low, upp);
        }
        int l=*(low.begin());
        int u=*(--upp.end());
        ret[nums.size()-k]=(k&1)?(double)l:((double)l + u) / 2;
        return ret;
    }
};
