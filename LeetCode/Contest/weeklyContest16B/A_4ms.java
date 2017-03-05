public class Solution {
    public int[] constructRectangle(int area) {
        int[] ret = new int[2];
    	for(int i=(int)(Math.sqrt(area) + 0.5);i>0;i--){
        	if(area % i == 0){
        		if(i>=area/i){
        			ret[0]=i;
        			ret[1]=area/i;
        		}
        		else {
        			ret[0]=area/i;
        			ret[1]=i;
        		}
        	}
        }
    	return ret;
    }
}