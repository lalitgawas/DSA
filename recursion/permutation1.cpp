class Solution {
public:
// TC:O(n*n!)=> n=n calls for each permute; n!=tot no of permutations
// SC:O(n!+n)=O(n!) => n=recursion tree depth;n!=tot permutations array ans
    void printPerm(vector<int>& nums,int idx,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back({nums});
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            printPerm(nums,idx+1,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        printPerm(nums,0,ans);
        return ans;
        
    }
};