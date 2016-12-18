class Solution {
public:

    bool dfs(vector<string>& words, string wr, int len, int cnt) {
        if(len==0 && cnt>=2)return true;
        bool ret=false;
        for(int i=1;i<=wr.length();i++){
            string sub_str = wr.substr(0,i);
            int w = lower_bound(words.begin(), words.end(), sub_str) - words.begin();
            if(w<words.size() && strcmp(words[w].c_str(), sub_str.c_str())==0){
                if(dfs(words, wr.substr(i), len-i, cnt+1)){
                    ret=true;
                    break;
                }
            }
        }
        return ret;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end());
        vector<string> ret;
        for(int i=0;i<words.size();i++){
            if( dfs(words, words[i], words[i].length(), 0) ) ret.push_back(words[i]);
        }
        return ret;
    }
};
