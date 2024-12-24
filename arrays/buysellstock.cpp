#include <bits/stdc++.h>
using namespace std;
// brute (TLE) O(n2)
int maxProfit(vector<int>& prices){
    int maxCnt=0;
    if(n==1){
            return 0;
        }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n;j++){
            if(prices[j]>=prices[i]){
                maxCnt=max(maxCnt,prices[j]-prices[i]);
            }
        }
    }
    return maxCnt;
    
}

// optimal O(n)
 int maxProfit(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }
        int maxCnt=0;
        int bestbuy=prices[0];
        for(int i=1;i<prices.size();i++){
        if(prices[i]>bestbuy){
            maxCnt=max(maxCnt,prices[i]-bestbuy);
        }

        bestbuy=min(bestbuy,prices[i]);
    }
    return maxCnt;
    }