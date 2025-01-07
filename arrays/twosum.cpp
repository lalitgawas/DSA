// brute O(n2) 
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
    
// optimised O(nlogn + 2n)=>O(nlogn) 
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        vector<int> arr;
        int i=0;
        int j=nums.size()-1;
        int a=0; int b=0;
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                a=nums[i];
                b=nums[j];
                break;
            }
        }
        int k=0;
        for(int i=0;i<temp.size();i++){
            if(a==temp[i]||b==temp[i]){
                arr.push_back(i);
                k++;
            }
            if(k==2) break;
        }
        return arr;
    }

// most optimised O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){

            int first=nums[i];
            int sec=target-first;

            if(mp.find(sec)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[sec]);
                break;
            }
            mp[first]=i;
        }
        return ans;
    }
