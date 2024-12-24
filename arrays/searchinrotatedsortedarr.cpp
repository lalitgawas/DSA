// brute O(n)
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
         if(nums[i]==target) return i;
    }
    return -1;

    }

// optimised O(logn)
    int search(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target) return mid;

            if(nums[st]<=nums[mid]){
                if(nums[st]<=target && target<=nums[mid]){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }else{
                if(nums[mid]<=target && target<=nums[end]){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
      }
      return -1;
    }