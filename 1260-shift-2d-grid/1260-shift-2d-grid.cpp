class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       if( k == 0) return grid;
       int n = grid.size();
       int m = grid[0].size();
       int total = n*m;
       k = k%total ;
      if( k == 0) return grid;
      vector<vector<int>>ans(n,vector<int>(m));

      for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int ind = (i*m)+j;
            int next = (ind+k)%total;
            ans[next/m][next%m] = grid[i][j];
        }
      }
    
     return ans;



    }
};