class Solution {
public:

    map<string,string> ma;
    
    Solution(){
        ma.clear();
    }
    
    int findcycle(string s) {
        if(s.length()<5)return -1;
        for(int k=s.length();k>=2;k--){
            if(s.length()%k!=0)continue;
            int l=s.length()/k;
            int ok=1;
            for(int i=0;i<l;i++){
                for(int j=1;j<k;j++){
                    if(s[i]!=s[i+j*l]){
                        ok=0;
                        break;
                    }
                }
                if(!ok)break;
            }
            if(ok)return k;
        }
        return -1;
    }

    string encode(string s) {
        if(ma.find(s)!=ma.end()){
            return ma[s];
        }
        string ret;
        for(int i=1;i<=s.length();i++){
            int k=findcycle(s.substr(0,i));
            string t;
            if(k==-1){
                t=s.substr(0,i) + encode(s.substr(i,s.length()-i));
            }
            else {
                t=to_string(k)+"["+encode(s.substr(0,i/k))+"]"+encode(s.substr(i,s.length()-i));
            }
            if(ret.length()==0 || t.length()<ret.length()){
                ret=t;
            }
        }
        ma[s]=ret;
        return ret;
    }
};

