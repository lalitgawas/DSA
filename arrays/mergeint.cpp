// n=length of whole arr
// O(nlogn) + O(n) = O(nlogn)
vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<int> ans(2); 
        sort(nums.begin(),nums.end());
        
        int i=1;
            while(i<nums.size()){
            if((nums[i-1][0]>=nums[i][0]&& nums[i-1][0]<=nums[i][1]) || (nums[i-1][1]>=nums[i][0] && nums[i-1][1]<=nums[i][1]) || (nums[i][0]>=nums[i-1][0] && nums[i][0]<=nums[i-1][1])){
            
            ans[0]=min(nums[i][0],nums[i-1][0]);
            ans[1]=max(nums[i][1],nums[i-1][1]);

            nums[i-1]=ans;
            nums.erase(nums.begin()+i);
            }else{
                i++;
            }
            }
        return nums;
    }