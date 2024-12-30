// TC: O(8^n2); for each pos there are 8 choices so 8*8..8 till n2 boxes 
// SC: O(n2); recursion stack depth
    bool helper(vector<vector<int>>& grid,int r,int c,int n,int expVal){
        if(r<0||c<0||r>=n||c>=n||grid[r][c]!=expVal) return false;

        if(expVal==(n*n)-1) return true;
        
        int ans1=helper(grid,r-2,c+1,n,expVal+1);
        int ans2=helper(grid,r-1,c+2,n,expVal+1);
        int ans3=helper(grid,r+1,c+2,n,expVal+1);
        int ans4=helper(grid,r+2,c+1,n,expVal+1);
        int ans5=helper(grid,r+2,c-1,n,expVal+1);
        int ans6=helper(grid,r+1,c-2,n,expVal+1);
        int ans7=helper(grid,r-1,c-2,n,expVal+1);
        int ans8=helper(grid,r-2,c-1,n,expVal+1);

        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
    } 
    
    bool checkValidGrid(vector<vector<int>>& grid) {
       return helper(grid,0,0,grid.size(),0);
    }