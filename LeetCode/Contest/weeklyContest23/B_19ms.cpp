class Solution {
public:
    
    int time_to_int(string &s){
        return ((s[0]-'0')*10+s[1]-'0')*60 + ((s[3]-'0')*10+s[4]-'0');
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> a;
        for(string x: timePoints){
            a.push_back(time_to_int(x));
        }
        
        sort(a.begin(), a.end());
        int ret=0x37777777;
        for(int i=0;i<a.size();i++){
            ret = min((a[(i+1)%a.size()]-a[i]+1440)%1440,ret);
            ret = min(ret, (a[i]-a[(i+1)%a.size()]+1440)%1440);
        }
        return ret;
    }
};
