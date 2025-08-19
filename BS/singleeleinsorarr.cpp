class Solution {
public:
// optimised 
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int ans=0;
        if(nums.size()==1) return nums[i];
        while(i<=j){

            if(i==j) return ans=nums[i];

            if(nums[i]==nums[i+1]) i+=2;
            else return ans=nums[i];

            if( nums[j]==nums[j-1]) j-=2;
            else return ans=nums[j];
        }
        return ans;
    }

// optimised alt sol
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0; int end=n-1;
        int mid=0;
        while(st<=end){
            mid=st+(end-st)/2;
            if(st==mid && end==n-1) return nums[end];
            else if(st==mid && st==0) return nums[st];
            else if((mid<=n-2 && nums[mid]!=nums[mid+1]) && (mid>=1 && nums[mid]!=nums[mid-1])) return nums[mid];
            else if((mid>=1 && nums[mid-1]==nums[mid] && (mid+1)%2==0) || (mid>=1 && nums[mid-1]!=nums[mid] && (mid+1)%2!=0) ) st=mid+1;
            else end=mid-1;
        }
        return nums[mid];
    }
    
// brute
       int singleNonDuplicate(vector<int>& nums) {
            int n=nums.size();
            int ans=0;
            for(int i=0;i<n;i++){
                if(i<=n-2 && nums[i]==nums[i+1]){
                    i+=1;
                    continue;
                }else{
                  ans=nums[i];
                  break;  
                } 
            }
            return ans;
    }

// optimised
       int singleNonDuplicate(vector<int>& nums) {
            int n=nums.size();
            int st=0; int end = n-1;
            int mid=0;

            while(st<=end){
                mid=st+(end-st)/2;
                if((mid<=n-2 && nums[mid]!=nums[mid+1]) && (mid>=1 && nums[mid-1]!=nums[mid])) return nums[mid];
                else if((mid<=n-2 && nums[mid]==nums[mid+1] && mid%2==0) || (mid>=1 && nums[mid-1]==nums[mid] && mid%2!=0)){
                    st=mid+1;
                }else end=mid-1;
            }
            return nums[mid];
    }
};