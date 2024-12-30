// brute TC:O(n2); SC:O(1)
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int currSum=0;
            for(int j=i;j<nums.size();j++){
                currSum+=nums[j];
                if(currSum==k) cnt++;
            }
        }
        return cnt;
    }
    
// optimised (prefixsum and hashing approach) TC:O(n); SC:O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefixSum(n,0);
        int cnt=0;

        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        unordered_map<int,int> mp;

        for(int j=0;j<n;j++){
            if(prefixSum[j]==k) cnt++;

            int val=prefixSum[j]-k;

            if(mp.find(val)!=mp.end()){
                cnt+=mp[val];
            }

            if(mp.find(prefixSum[j])==mp.end()) mp[prefixSum[j]]=0;

            mp[prefixSum[j]]++;
        }
    return cnt;
    }