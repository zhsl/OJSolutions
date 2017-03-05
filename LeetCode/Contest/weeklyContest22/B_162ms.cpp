class Solution {
public:

    static const int N=510;
    
    int row[N],col[N];
    
    int findLonelyPixel(vector<vector<char>>& picture) {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<picture.size();i++) {
            for(int j=0;j<picture[i].size();j++){
                if(picture[i][j]=='B') row[i]++,col[j]++;   
            }
        }
        
        int ans=0;
        for(int i=0;i<picture.size();i++) {
            for(int j=0;j<picture[i].size();j++){
                if(row[i]==1 && row[i]==col[j] && picture[i][j]=='B') ans++;
            }
        }
        return ans;
    }
};



