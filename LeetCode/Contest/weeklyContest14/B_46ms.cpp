class Solution {
public:
    static const int N = 100010;
    int s[N];
    int f[N];
    
    Solution() {
        s[0]=0;
        s[1]=1,s[2]=2;
        int v=1;
        for(int i=1,j=1;j<N-5;i++){
            if(s[i]==1){
                s[j]=v;
                j++;
            }
            else {
                s[j]=v;
                s[++j]=v;
                j++;
            }
            v=(v==1?2:1);
        }
        f[0]=0;
        for(int i=1;i<N-5;i++){
            f[i]=f[i-1]+(s[i]==1);
        }
    }
    
    int magicalString(int n) {
        return f[n];
    }
};
