class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n =  grid.size();
        vector<int>prev(n,0);
        for(int i = 0;i<n;i++){
            prev[i] = grid[0][i];
        }
        for(int i = 1;i<n;i++){
            vector<int>cur(n,0);
            for(int j = 0;j<n;j++){
              int left = INT_MAX,center = INT_MAX,right = INT_MAX;
              if(j > 0) left = prev[j-1];
              if(j+1 < n) right = prev[j+1];
              center = prev[j];
              cur[j] = grid[i][j] + min(center,min(left,right));
            }
            prev = cur;
        }
        
        int minPath = INT_MAX;
          for(int i = 0;i<n;i++){
            minPath = min(prev[i],minPath);
        }
        return minPath;
         
    }
};