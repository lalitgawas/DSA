// brute O(n2)
int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] < nums[j]){
                    continue;
                }
                double b = static_cast<double>(nums[i]/2.0);
                if(b>(nums[j])){
                    count++;
                }
            }
        }
        return count;
    }

// optimal O(logn) * O(n+n) = O(2nlogn) =O(nlogn)
// logn is for mergeSort step ,the levels of mergreSort tree and at each level n+n is happening
// one n is for merge step and other is for counting pairs
 void merge(vector<int>& nums,int low,int mid,int high){
        vector<int> temp;
        int left=low; int right=mid+1;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
        temp.push_back(nums[left]);
        left++;
        }
        while(right<=high){
        temp.push_back(nums[right]);
        right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return;
    }

    int countPairs(vector<int>& nums, int low,int mid,int high){
        int right=mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++){
            double b=nums[i]/2.0;
            while(right<=high && b>nums[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }


    int mergeSort(vector<int>& nums, int low,int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid=low+(high-low)/2;

        cnt+=mergeSort(nums,low,mid);
        cnt+=mergeSort(nums,mid+1,high);
        cnt+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }