class Solution {
public:
// brute O( > n! * n)
   void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx) {
    if (idx == nums.size()) {


        if(ans.size()>0){
            for(int a=0;a<ans.size();a++){
                int m=0;
                for(int b=0;b<nums.size();b++){
                   
                    if( ans[a][b]==nums[m]) {
                        
                        if(nums.size()-1==(m)){
                            return;
                        }
                        m++;
                    }
                    
                }
            }
            }
        ans.push_back(nums); 
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
      
        if (i > idx && nums[i] == nums[i-1]) continue;
        swap(nums[idx], nums[i]);         
        backtrack(nums, ans, idx + 1); 
        swap(nums[idx], nums[i]);         
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    
    vector<vector<int>> ans;
    backtrack(nums, ans, 0);
    return ans;
}


// thoda aur optimised O(n * n!)
   void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx,unordered_map <string,int>& mp) {
    if (idx == nums.size()) {
        string result = accumulate(nums.begin(), nums.end(), string(),
                                         [](const string &a, int b) {
                                             return a + to_string(b);
                                         });
        if(mp.find(result)!=mp.end()){
            return;
        }else{
            mp.insert({result,1});
            ans.push_back(nums); 
            return;
        }
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);         
        backtrack(nums, ans, idx + 1,mp); 
        swap(nums[idx], nums[i]);         
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    unordered_map<string,int> mp;
    vector<vector<int>> ans;
    backtrack(nums, ans, 0,mp);
    return ans;
}
};