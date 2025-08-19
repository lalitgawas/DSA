class Solution {
public:
// 1
    bool search(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target) return true;

            if(nums[st]<nums[mid]){
                if(nums[st]<=target && target<=nums[mid]){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }else if(nums[st]==nums[mid]){
                if(st==mid){
                    st=mid+1;
                }else{
                bool flag=false;
                for(int i=st+1;i<mid;i++){
                    if(nums[i]!=target){
                        continue;
                    }else{
                        flag=true;
                        break;
                    }
                }
                if(flag){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
                }

            }
            else{
                if(nums[mid]<=target && target<=nums[end]){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
      }
      return false;   
    }

// 2
    bool search(vector<int>& nums, int tar) {
        int n=nums.size();
    int st=0; int end=n-1; 
    bool flag=false;

    while(st<=end){
        int mid=st+(end-st)/2;
        if(tar==nums[mid]){
                flag=true;
                break;
            }
        if(nums[st]<=nums[mid] && nums[mid]>nums[end]){
             if(tar<nums[mid] && tar>=nums[st]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }else if(nums[mid]<=nums[end] && nums[st]>nums[mid]){
            if(tar>nums[mid] && tar<=nums[end]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }else{
            if(nums[st]==nums[mid] && nums[mid]==nums[end]){
                for(int i=mid;i<n;i++){
                    if(nums[i]==tar) return flag=true;
                }
                for(int j=mid;j>=0;j--){
                    if(nums[j]==tar) return flag=true;
                }
                if(!flag) return flag=false;
            }
            
            if(tar>nums[mid]) st=mid+1;
            else end=mid-1;
        }
    }if(st>end){
        return flag;
    }
    return flag;
    }
};

