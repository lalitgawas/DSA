// brute TC: O(n3 * log(unique triplets)) (TLE) ; log wala term set ke find aur insert ki vjh se aye;
// unordered set takes O(1) but also set is taken coz its easy to store vector or pairs in set than unordered; set takes log(n) time
// SC: O(uniquetriplets * 2)->O(uniquetriplets) ;one is of ans vector and other is of set data structure
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        
        set<vector<int>> s;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){

                    if(nums[i]+nums[j]+nums[k]==0){

                        vector<int> trip={nums[i],nums[j],nums[k]};
                        sort(trip.begin(),trip.end());
                        
                        // if(s.find(trip)==s.end()){
                            s.insert(trip);
                            // ans.push_back(trip);
                        // }
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }


// // little bit optimised TC: O(n2 * log(unique triplets)) (TLE) ; log wala term set ke find aur insert ki vjh se aye; SC: O(uniquetriplets + n) ; that n is coz of extra set of s
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> uniqueTrips;

        for(int i=0;i<n;i++){

            int tar=-nums[i];
            set<int> s;

            for(int j=i+1;j<n;j++){

                int c=tar-nums[j];
                if(s.find(c)!=s.end()){
                    vector<int> trip={nums[i],nums[j],c};
                    sort(trip.begin(),trip.end());
                    uniqueTrips.insert(trip);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(uniqueTrips.begin(),uniqueTrips.end());
        return ans;
    }


// optimised (2pointer approach) TC: O(nlogn + n2); SC:O(uniquetriplets)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans; 
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j=i+1; int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]>0) k--;
                else if(nums[i]+nums[j]+nums[k]<0) j++;
                else{
                    ans.push_back({nums[i],nums[k],nums[j]});
                    k--; j++;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }
        }
    return ans;
    }