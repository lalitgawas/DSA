class Solution {
public:
    string getPermutation(int n, int k) {
    int fact=1;
    vector<int> nums;
    string s ="";
    for (int i = 1; i < n; i++) {
        fact=fact*i;
        nums.push_back(i);
    }
    nums.push_back(n);
    k=k-1;
    while(true){
        s=s+ to_string(nums[k/fact]);
        nums.erase(nums.begin() + k/fact);
        if(nums.size()==0){
            break;
        }
        k=k%fact;
        fact=fact/nums.size();
    }
    return s;
    
    }
};