public class Solution {
	
	static final long INF = (long)Math.pow(10, 18) + 1;
	
	public long getValue(long k, int len){
		if(Math.pow(k, len-1) > (double)INF)return INF;
		long ret=0,t=1;
		for(int i=0;i<len;i++,t*=k){
			ret+=t;
			if(ret>=INF || t>=INF || ret<0){
				ret=INF;
				break;
			}
		}
		return ret;
	}
	
	public long isok(int len, long tar){
		long l=2,r=tar;
		while(l<=r){
			long mid=(l+r)/2;
			long value = getValue(mid, len);
			if(value==tar){
				return mid;
			}
			else if(value<tar)l=mid+1;
			else r=mid-1;
		}
		return 0;
	}
	
    public String smallestGoodBase(String n) {
    	long tar = Long.parseLong(n);
    	String ret = "";
    	for(int i=63;i>=2;i--){
    		long ans = isok(i, tar);
    		if(ans>0) {
    		    ret = Long.toString(ans);
    		    break;
    		}
    	}
    	return ret;
    }
}