int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int cnt=0,ret=0;
    for(int i=0;i<numsSize;){
        if(nums[i]!=1){
            i++;
            continue;
        }
        cnt=0;
        while(i< numsSize && nums[i]==1){
            cnt++;
            i++;
        }
        if(cnt>ret)ret=cnt;
    }
    return ret;
}
