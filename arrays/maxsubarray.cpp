// for a n size arr no of sub arr equal to n(n+1)/2
// brute O(n2) TLE
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        for(int st=0;st<nums.size();st++ ){
            int curSum=0;
            for(int end=st;end<nums.size();end++){
                curSum+=nums[end];
                maxSum=max(curSum,maxSum);
            }
        }
        return maxSum;
   
    }


// optimised O(n) kadanes algo
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int curSum=0;
        for(int i=0;i<nums.size();i++){
            curSum+=nums[i];
            maxSum=max(curSum,maxSum);
            if(curSum<0) curSum=0;
        }
        return maxSum;
    }