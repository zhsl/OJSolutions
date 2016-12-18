int totalHammingDistance(int* nums, int numsSize) {
    int ret=0;
    for(int i=0;i<31;i++){
        int zero=0,one=0;
        for(int j=0;j<numsSize;j++){
            if(nums[j]&(1<<i))one++;
            else zero++;
        }
        ret+=zero*one;
    }
    return ret;
}
