class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();
          vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
          for(int j1 = 0 ;j1<m;j1++){
            for(int j2 = 0;j2<m;j2++){
                 if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
             else dp[n-1][j1][j2] =  grid[n-1][j1]+grid[n-1][j2];
            }
          }

          for(int i = n-2; i>=0;i--){
              for(int j1 = 0 ;j1<m;j1++){
            for(int j2 = 0;j2<m;j2++){
                   for(int l = -1;l < 2;l++){
                 for(int r = -1;r<2;r++){
                     int value = grid[i][j1];
                     if(j1 != j2) value+=grid[i][j2];
                     if(j1+l >= 0 && j1+l < m && j2+r >= 0 && j2+r < m){
                        value+=dp[i+1][j1+l][j2+r];
                     } 
                     else value+=(-1e8); 
                     dp[i][j1][j2] = max(dp[i][j1][j2] , value); 
               
             }
             }
            }
          }
          }
          return dp[0][0][m-1];
        
    }
};