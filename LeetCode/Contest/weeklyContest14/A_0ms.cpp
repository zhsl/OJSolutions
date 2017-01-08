int findComplement(int num) {
    int ret = 0;
    int i = 31;
    while(!(num&(1<<i)))i--;
    while(i>=0){
        if(!(num&(1<<i))){
            ret += (1<<i);
        }
        i--;
    }
    return ret;
}
