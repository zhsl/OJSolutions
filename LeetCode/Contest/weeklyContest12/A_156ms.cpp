class Solution {
public:
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ret=0,l=0,r=houses.size()-1;
        ret=max(ret,heaters[0]-houses[0]);
        ret=max(ret,houses[houses.size()-1]-heaters[heaters.size()-1]);
        while(l<houses.size() && houses[l]<heaters[0]) l++;
        while(r>=0 && houses[r]>=heaters[heaters.size()-1]) r--;
        int p=0;
        for(;l<=r;l++) {
            while(houses[l]>=heaters[p+1])p++;
            int t=min(houses[l]-heaters[p], heaters[p+1]-houses[l]);
            ret=max(ret,t);
        }
        return ret;
    }
};
