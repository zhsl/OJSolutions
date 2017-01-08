char* licenseKeyFormatting(char* S, int K) {
    char ret[12010];
    int d=0,len=0;
    for(int i=0;S[i];i++,len++){
        if(S[i]=='-')d++;
        if(S[i]>='a' && S[i]<='z')S[i]=S[i]-'a'+'A';
    }
    int w=0;
    for(int i=len,cnt=0;i--;){
        if(S[i]=='-')continue;
        if(cnt==K){
            ret[w++]='-';
            cnt=0;
        }
        ret[w++]=S[i];
        cnt++;
    }
    ret[w]=0;
    for(int i=0;i<(w>>1);i++){
        char t = ret[i];
        ret[i]=ret[w-i-1];
        ret[w-i-1]=t;
    }
    char *p=ret;
    return p;
}
