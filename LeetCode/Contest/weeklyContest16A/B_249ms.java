public class Solution {
    
    static final int N=30;
    
    int[] suf = new int[N];
    
    int dfs(int[] nums, int d, int sum, int S) {
        if(d==nums.length) return sum==S?1:0;
        int ret=0;
        int t=sum+nums[d];
        if((t <= S && t+suf[d+1] >= S) || (t >= S && t-suf[d+1] <= S))
            ret += dfs(nums, d+1, sum+nums[d], S);
        t=sum-nums[d];
        if((t <= S && t+suf[d+1] >= S) || (t >= S && t-suf[d+1] <= S))
            ret += dfs(nums, d+1, sum-nums[d], S);
        return ret;
    }
    
    public int findTargetSumWays(int[] nums, int S) {
        suf[nums.length]=0;
        for(int i=nums.length-1;i>=0;i--){
           suf[i]=suf[i+1]+nums[i];
        }
        
        return dfs(nums, 0, 0, S);
    }
}