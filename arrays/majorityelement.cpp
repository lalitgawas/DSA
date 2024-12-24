// for an array of length n the max subarrays = n(n+1)/2
// brute O(n2)
    int majorityElement(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int freq=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]) freq++;
            }
            if(freq>nums.size()/2){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }

    // optimised O(nlogn)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int freq=1;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
             freq++;
            }    
            
            else {
                if(freq>nums.size()/2){
                ans=nums[i];
                break;
                }
                else{
                freq=1;
                }  
            } 
             if(freq>nums.size()/2){
                ans=nums[i];
                break;
                }
            
        }
        return ans;
    }

    // more optimised O(n) moores algo
    int majorityElement(vector<int>& nums) {
        int freq=0; int ans=0;
        for(int i=0;i<nums.size();i++){
            if(freq==0){
                ans=nums[i];
            }
            if(ans==nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        return ans;
    }
    
// most optimised O(n)
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int idx;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxCnt=INT_MIN;
        int ans=0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans=it->second;
            if(ans>n/2){
                if(ans>maxCnt){
                    maxCnt=ans;
                    idx=it->first;
                }
            }
        }
        return idx;
    }