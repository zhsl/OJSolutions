int hammingDistance(int x, int y) {
    int ret=0;
    for(int i=0;i<31;i++){
        if( (x&(1<<i))^((y&(1<<i)))) {
            ret ++;
        }
    }
    return ret;
}
