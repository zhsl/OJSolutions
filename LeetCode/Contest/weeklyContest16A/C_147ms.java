import java.util.*;

public class Solution {
    
    List<List<Integer>> ret;
    Set<String> set;
    
    String InttoString(Vector<Integer> vis){
    	String ret="";
    	for(Integer x: vis){
    		ret+=x.toString()+",";
    	}
    	return ret;
    }
    
    int dfs(int[] nums, int d,Vector<Integer> vis) {
        if(d==nums.length){
            String temp = InttoString(vis);
        	if(vis.size()>=2 && set.contains(temp)==false){
        	    set.add(temp);
        		ret.add(new ArrayList<Integer>(vis));
        	}
        	return 1;
        }
        if(vis.isEmpty() || nums[d]>=vis.lastElement()){
        	vis.add(nums[d]);
        	dfs(nums, d+1, vis);
        	vis.remove(vis.size()-1);
        }
        dfs(nums, d+1, vis);
    	return 1;
    }
    
    public List<List<Integer>> findSubsequences(int[] nums) {
        ret = new ArrayList<List<Integer>>();
        set = new HashSet<String>();
        Vector<Integer> vis = new Vector<Integer>();
        dfs(nums, 0, vis);
        return ret;
    }
}