class Solution {
public:
// TC:O(n)
    int findPeakElement(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1) return 0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                if(nums[i+1]<nums[i]){
                    return ans=i;
                }
            }
            if(i==nums.size()-1){
                if(nums[i-1]<nums[i]){
                    return ans=i;
                }
            }

            if(i>0 && i<nums.size()-1 && nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                return ans=i;
            }
        }
        return ans;
    }
    // TC:O(logn)
    int findPeakElement(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        int mid=0;
        if(nums.size()==1) return 0;

        while(st<=end){
            mid=st+(end-st)/2;
            if(mid==0){
                if(nums[mid]<nums[mid+1]){
                    st=mid+1;
                    continue;
                }else{
                    return 0;
                }
            }
            if(mid==nums.size()-1){
                if(nums[mid]>nums[mid-1]){
                    return mid;
                }
            }

            if(mid>0 && mid<nums.size()-1 && nums[mid]>nums[mid+1] && nums[mid]<nums[mid-1]){
                end=mid-1;
            }else if(mid>0 && mid<nums.size()-1 && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                st=mid+1;
            }else if(mid>0 && mid<nums.size()-1 && nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1])      {
                st=mid+1;
            }
            else{
                return mid;
            }
        }
        return mid;
    }
};