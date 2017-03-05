public class Solution {
    
    int[] dfs(int[] nums, int d, int l, int r) {
        if(l==r){
            return d==1?new int[] {0,nums[l]}:new int[] {nums[l],0};
        }
        int[] ret1 = dfs(nums, (d+1)&1, l+1, r);
        ret1[d]+=nums[l];
        int[] ret2 = dfs(nums, (d+1)&1, l, r-1);
        ret2[d]+=nums[r];
        return ret1[d]>ret2[d]?ret1:ret2;
    }
    
    public boolean PredictTheWinner(int[] nums) {
        int[] ret = dfs(nums, 0, 0, nums.length-1);
        return ret[0]>=ret[1];
    }
}