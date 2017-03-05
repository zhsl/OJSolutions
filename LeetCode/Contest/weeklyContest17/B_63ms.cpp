class Solution {
public:
    
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0, pre=-1;
        for(int ele: timeSeries){
            ans+=ele > pre?duration:duration-(pre-ele+1);
            pre=ele-1+duration;
        }
        return ans;
    }
};