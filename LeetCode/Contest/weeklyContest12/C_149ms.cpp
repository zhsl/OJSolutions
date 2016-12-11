int findMaxForm(char** strs, int strsSize, int m, int n) {
    
    inline int max(int a,int b){
        return a>b?a:b;
    }
    
    int cnt[610][2];
    int f[110][110];
    memset(cnt,0,sizeof(cnt));
    memset(f,0,sizeof(f));
    for(int i=0;i<strsSize;i++){
        for(int j=0;strs[i][j];j++){
            if(strs[i][j]=='0')cnt[i][0]++;
            else cnt[i][1]++;
        }
    }

    int ret=0;
    for(int k=0;k<strsSize;k++) {
        for(int i=m;i>=cnt[k][0];i--){
            for(int j=n;j>=cnt[k][1];j--){
                f[i][j]=max(f[i][j], f[i-cnt[k][0]][j-cnt[k][1]]+1);
                ret=max(ret,f[i][j]);
            }
        }
    }
    return ret;
}
