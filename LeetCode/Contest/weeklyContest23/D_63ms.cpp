class Solution {
public:

    static int cmp(pair<string, int> &a, pair<string, int> &b) {
        return a.first < b.first;
    }

    vector<string> wordsAbbreviation(vector<string>& dict) {
        map<string, vector<pair<string, int> > > t;
        vector<string> ret(dict.size());
        for(int i=0;i<dict.size();i++) {
            if(dict[i].length()<=3){
                ret[i] = dict[i];
            }
            else {
                string s = dict[i][0] + to_string(dict[i].length()-2) + dict[i][dict[i].length()-1];
                t[s].push_back(make_pair(dict[i], i));
            }
        }
        map<string, vector<pair<string, int> > >::iterator it;
        for(it = t.begin(); it!=t.end(); it++){
            vector<pair<string, int> >& p = it->second;
            sort(p.begin(), p.end(), cmp);
            int len=p.size();
            int pre_b=0;
            int i=0;
            for(i=0;i<len-1;i++){
                int a=0,b=0;
                string& s1=p[i].first, s2=p[i+1].first;
                while(s1[a]==s2[b]){
                    a++,b++;
                }
                int w=max(pre_b,a);
                if(s1.length()-w-2>=2)
                    ret[p[i].second] = s1.substr(0, w+1) + to_string(s1.length()-w-2) + s1[s1.length()-1];
                else ret[p[i].second] = s1;
                pre_b=b;
            }
            int w=pre_b;
            string &s1 = p[i].first;
            if(s1.length()-w-2>=2)
                ret[p[i].second] = s1.substr(0, w+1) + to_string(s1.length()-w-2) + s1[s1.length()-1];
            else ret[p[i].second] = s1;
        }
        
        return ret;
    }
};
