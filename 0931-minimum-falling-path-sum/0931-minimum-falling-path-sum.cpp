class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n =  grid.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = 0;i<n;i++){
            dp[0][i] = grid[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
              int left = INT_MAX,center = INT_MAX,right = INT_MAX;
              if(j > 0) left = dp[i-1][j-1];
              if(j+1 < n) right = dp[i-1][j+1];
              center = dp[i-1][j];
              dp[i][j] = grid[i][j] + min(center,min(left,right));
            }
        }
        
        int minPath = INT_MAX;
          for(int i = 0;i<n;i++){
            minPath = min(dp[n-1][i],minPath);
        }
        return minPath;
         
    }
};