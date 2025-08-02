// brute O(n2)
int maxProduct(vector<int>& nums) {
        int currP=1;
        int maxP=INT_MIN;

        for(int i=0;i<nums.size();i++){
            currP=1;
            for(int j=i;j<nums.size();j++){
                currP*=nums[j];
                maxP=max(maxP,currP);
            }
        }
        return maxP;
    }

// optimal O(n)
int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int pre=1;
        int suff=1;
        int n=nums.size();

        for(int i=0;i<nums.size();i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;

            pre*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pre,suff));

        }
        return ans;
}