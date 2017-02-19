class Solution {
public:
    
    int INF = 0x3f3f3f3f;
    int cnt[10010];

    int findMinMoves(vector<int>& machine) {
        int sum=0;
        for(int i=0;i<machine.size();i++){
            sum+=machine[i];
        }
        if(sum % machine.size() !=0) return -1;
        int val = sum / machine.size();
        memset(cnt,0,sizeof(cnt));
        
        int ans=0;
        for(int i=0;i<machine.size()-1;i++) {
            if(machine[i]>=val){
                cnt[i] += machine[i] - val;
                machine[i+1] += machine[i] - val;
            }
            else {
                cnt[i+1] += val - machine[i];
                machine[i+1] -= val - machine[i];
            }
        }
        for(int x: cnt){
            if(x > ans)ans=x;
        }
        return ans;
    };
};
