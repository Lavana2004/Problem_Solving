int maxSubArray(int*a , int n) {
    int maxsum=a[0],currsum=a[0];
    for(int i=1;i<n;i++)
    {
        if(currsum<0)
           currsum=0;
           currsum=currsum+a[i];
        if(maxsum<currsum)
           maxsum=currsum;
    }
    return maxsum;
    
}