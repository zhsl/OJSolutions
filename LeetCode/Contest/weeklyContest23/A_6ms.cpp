class Solution {
public:

    string reverseStr(string s, int k) {
        int i=0;
        for(i=0;i<s.length() && s.length()-i >= k;){
            int si=i;
            for(int j=i+k-1;i<j;j--,i++){
                char t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
            i=si+(k<<1);
        }
        for(int j=s.length()-1;i<j;j--,i++){
            char t=s[i];
            s[i]=s[j];
            s[j]=t;
        }
        return s;
    }
};
