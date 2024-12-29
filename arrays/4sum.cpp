class Solution {
public:
// brute TC:O(nlogn + n4) SC: O(unique quadruplets)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;){
                for(int k=j+1;k<n;){
                    for(int m=k+1;m<n;){
                        if((long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[m]==target){
                            ans.push_back({nums[i],nums[j],nums[k],nums[m]});
                            m++;
                            while(m<n && nums[m]==nums[m-1]) m++;
                            continue;
                        }
                        m++;
                        while(m<n && nums[m]==nums[m-1]) m++;
                    }
                    k++;
                    while(k<n && nums[k]==nums[k-1]) k++;
                }
                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
        }
    return ans;
    }

// optimised (2pointer approach) TC: O(nlogn + n3); SC:O(uniquetriplets)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;){
            int k=j+1; int l=n-1;
            while(k<l){
                long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                if(sum>target) l--;
                else if(sum<target) k++;
                else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                } 
            }
        j++;
        while(j<n && nums[j]==nums[j-1]) j++;
        }
        }
        return ans;
    }
};