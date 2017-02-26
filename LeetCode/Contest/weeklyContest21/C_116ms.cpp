class Solution {
public:
    vector<string> ret;
    
    bool isok(string a, string b){
        int k=0;
        int cnt=0;
        for(int i=0;i<b.length();i++){
            for(;k<a.length() && a[k]!=b[i];k++){}
            if(k==a.length())return false;
            k++;
        }
        return true;
    }

    static int cmp(string a,string b){
        return a.length()==b.length()?strcmp(a.c_str(),b.c_str())<0:a.length()>b.length();
    }

    string findLongestWord(string s, vector<string>& d) {
        ret.clear();
        for(int i=0;i<d.size();i++){
            if(isok(s,d[i])){
                ret.push_back(d[i]);
            }
        }
        
        if(ret.size()==0)return "";
        sort(ret.begin(),ret.end(),cmp);

        return ret[0];
    }
};
