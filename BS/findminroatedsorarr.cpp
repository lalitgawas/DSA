class Solution {
public:

// brute
    int findMin(vector<int>& nums) {
   int n=nums.size();
   int min=nums[0];

   for(int i=1;i<n;i++){
    if(min>nums[i]){
        min=nums[i];
    }
   }
   return min;
 }


// optimised 
    // int findMin(vector<int>& nums) {
    //     int n=nums.size();
    //     int st=0;
    //     int end=n-1;
        
    //     while(st<=end){
    //         int mid=st+(end-st)/2;
    //         if(nums[st]<=nums[mid] && nums[mid]<=nums[end]){
    //             return nums[st];
    //         }
    //         else if(nums[st]<=nums[mid] && nums[mid]>=nums[end]){
    //             st=mid+1;
    //         }else{
    //             end=mid;
    //         }
    //     }
    //     return nums[st];
    // }

// optimised alt sol
    // int findMin(vector<int>& nums) {
    //    int n=nums.size();
    //    int st=0; int end=n-1;
    //    if(n==1) return nums[0];
    //     int mid=0;
    //     while(st<=end){
    //         mid=st+(end-st)/2;
    //         if((mid>=1 && nums[mid-1]>nums[mid]) && (mid<=n-2 && nums[mid]<nums[mid+1])){
    //             return nums[mid];
    //         }
    //         else if((nums[st]<=nums[mid] && nums[mid]<=nums[end])||(nums[st]>nums[mid] && nums[mid]<=nums[end])){
    //             end=mid-1;
    //         }
    //         else{
    //             st=mid+1;
    //         }
    //     }
    //    return nums[mid];
    // }
};