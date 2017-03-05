class Solution {
public:

    string kb[3];
    
    Solution(){
        kb[0]="qwertyuiop";
        kb[1]="asdfghjkl";
        kb[2]="zxcvbnm";
    }
    
    int contain(int k, char c){
        for(char x: kb[k]){
            if(x==c || x==(c-'A'+'a'))return 1;
        }
        return 0;
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        for(int i=0;i<words.size();i++){
            for(int k=0;k<3;k++){
                int ok=1;
                for(int j=0;j<words[i].length();j++){
                    if(!contain(k, words[i][j])){
                        ok=0;
                        break;
                    }
                }
                if(ok==1){
                    ret.push_back(words[i]);
                    break;
                }
            }
        }
        return ret;
    }
};



