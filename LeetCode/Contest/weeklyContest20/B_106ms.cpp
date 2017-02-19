class Solution {
public:

    int vis[20];

    int find(int p, int N){
        if(p==N){
            return 1;
        }
        int ret=0;
        for(int i=1;i<=N;i++){
            if(vis[i])continue;
            if(!(i%(p+1)) || !((p+1)%i)){
                vis[i]=1;
                ret += find(p+1, N);
                vis[i]=0;
            }
        }
        return ret;
    }

    int countArrangement(int N) {
        memset(vis,0,sizeof(vis));
        return find(0, N);
    }
};
