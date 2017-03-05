class Solution {
public:
    
    static const int INF = 0x3f3f3f3f;
    int d[110][110];

    int gets(int i, int j, int lenr){
        return min(abs(i-j), lenr-abs(i-j));
    }

    int findRotateSteps(string ring, string key) {
        int lenr=ring.length();
        int lenk=key.length();
        memset(d,INF,sizeof(d));
        for(int i=0;i<lenr;i++){
            if(ring[i]==key[0]) d[0][i]=gets(0,i,lenr)+1;
        }
        
        for(int k=1;k<lenk;k++){
            for(int i=0;i<lenr;i++){
                if(ring[i]!=key[k])continue;
                for(int j=0;j<lenr;j++){
                    d[k][i]=min(d[k][i], d[k-1][j]+gets(i,j,lenr)+1);
                }
            }
        }
        
        int ans=INF;
        for(int i=0;i<ring.length();i++){
            ans=min(ans,d[lenk-1][i]);
        }
        return ans;
    }
};
