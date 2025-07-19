class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal=*max_element(piles.begin(),piles.end());
        int n=piles.size();
        int st=1;
        int end=maxVal;
        int ans=0;   
        long long result=0;

        while(st<=end){
          int mid=st+(end-st)/2;

            for(int j=0;j<n;j++){
                result+=ceil(static_cast<double>(piles[j])/mid);
            }

            if(result>h){
                st=mid+1;
                result=0;
            }else{
                ans=mid;
                result=0;
                end=mid-1;
            }
        }   
        return ans;
    }

// brute n+n2=O(n2)
    int minEatingSpeed(vector<int>& nums, int h) {
        int n=nums.size();
        long long tot=*max_element(nums.begin(), nums.end());
        long long st=tot/h;
        if(st==0) st=1;

        for(long long i=st;i<=tot;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                if(nums[j]%i!=0){
                    sum=sum+(nums[j]/i + 1);
                }else{
                    sum+=nums[j]/i;
                }
            }
            if(sum<=h)return i;
        }
        return 0;
    }

// little optimised n+nlogn= O(nlogn)
    int minEatingSpeed(vector<int>& nums, int h) {
        int n=nums.size();
        long long tot=*max_element(nums.begin(), nums.end());
        long long st=tot/h;
        if(st==0) st=1;
        long long end=tot;
        int min=INT_MAX;

        while(st<=end){
            long long mid=st+(end-st)/2;
            long long sum=0;
            for(int j=0;j<n;j++){
                if(nums[j]%mid!=0){
                    sum=sum+(nums[j]/mid + 1);
                }else{
                    sum+=nums[j]/mid;
                }
            }
            if(sum>h) st=mid+1;
            else{
                end=mid-1;
                if(mid<min){
                    min=mid;
                }
            }
        }
        return min;
    }
};