// brute (TLE) O(n2)

    int maxArea(vector<int>& height) {
        int maxCnt=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
            int width=j-i;
            int heights=min(height[i],height[j]);
            maxCnt=max(maxCnt,heights*width);
            }
        }
        return maxCnt;
    }


// optimal O(n)
    int maxArea(vector<int>& height) {
        int maxCnt=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int width=j-i;
            int heights=min(height[i],height[j]);
            maxCnt=max(maxCnt,heights*width);
            height[i]<height[j] ? i++:j--;
        }
        return maxCnt;
    }