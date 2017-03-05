class Solution {
public:
    static const int M=510;

    int row[M],col[M];
    int iseq[M][M];

    int findBlackPixel(vector<vector<char>>& picture, int N) {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<picture.size();i++) {
            for(int j=0;j<picture[i].size();j++){
                if(picture[i][j]=='B') row[i]++,col[j]++;
            }
        }

        for(int i=0;i<picture.size();i++){
            iseq[i][i]=1;
            for(int j=i+1;j<picture.size();j++){
                iseq[i][j]=iseq[j][i]=1;
                for(int k=0;k<picture[0].size();k++){
                    if(picture[i][k]!=picture[j][k]){
                        iseq[i][j]=iseq[j][i]=0;
                        break;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<picture.size();i++) {
            for(int j=0;j<picture[i].size();j++){
                if(row[i]==N && row[i]==col[j] && picture[i][j]=='B'){
                    int ok=1;
                    for(int k=0;k<picture.size();k++){
                        if(picture[k][j]=='B' && !iseq[i][k]){
                            ok=0;
                            break;
                        }
                    }
                    ans+=ok;
                }
            }
        }
        return ans;
    }
};


