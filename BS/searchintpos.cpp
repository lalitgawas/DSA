class Solution {
public:
// optimal
    int searchInsert(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        int ans=0;
        if(nums.size()==1){
            if(nums[st]==target || nums[st]>target) return st;
            else return st+1;
        }

        while(st<end || st>=end){

            if(st>end){
                if(nums[ans]<target || nums[ans]>target ){
                    return end+1;
                }
            }
            else{
               int mid=st+(end-st)/2;
            ans=mid;
            if(nums[ans]>target){
                end=ans-1;
            }
            else if(nums[ans]<target){
                st=ans+1;
            }else{
                return ans;
            } 
            }
            
        }
        return ans;
    }

    // brute
    int searchInsert(vector<int>& nums, int target) {
       int n=nums.size();
        int ans=0;
        if(n==1){
            if(nums[n-1]==target) return n-1;
            else if(nums[n-1]>target) return n-1;
            else return n;
        }

       for(int i=0;i<n;i++){
        if(nums[i]<=target){
            if(i==n-1){
                ans= i+1;
            }
            if(nums[i]==target){
                return ans= i;
            }
        }else{
            return ans= i;
        }
       }
       return ans;
    }
};