class Solution {
public:

    set<int> ma;
    set<pair<int,int>> mans;

    int findPairs(vector<int>& nums, int k) {
        if(k<0)return 0;
        ma.clear();
        mans.clear();
        int ans=0;
        for(int x: nums){
            if(ma.find(x-k)!=ma.end()){
                int y=x-k;
                if(mans.find(make_pair(x,y))==mans.end()){
                    mans.insert(make_pair(x,y));
                    mans.insert(make_pair(y,x));
                    ans++;
                }
            }
            if(ma.find(x+k)!=ma.end()){
                int y=x+k;
                if(mans.find(make_pair(x,y))==mans.end()){
                    mans.insert(make_pair(x,y));
                    mans.insert(make_pair(y,x));
                    ans++;
                }
            }
            if(ma.find(x)==ma.end())ma.insert(x);
        }
        
        return ans;
    }
};