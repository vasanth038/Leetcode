class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
     vector<vector<int>> vis(n, vector<int>(m, 0));
     queue<pair<pair<int,int> , int>>q;
      
      for(int i = 0; i<n;i++){
        for(int j = 0 ;j<m;j++){
            if(grid[i][j] == 2) {
                q.push({{i,j},0});
                vis[i][j] = 2;
            } 
        }
      }
      int max_time = 0;
        vector<int>r = { -1 , 0 ,1 , 0};
        vector<int>c = { 0 , -1 , 0 ,1} ;
      while(!q.empty()){
        
          auto it = q.front().first;
          int t = q.front().second ;
          q.pop(); 
          int i = it.first;
          int j = it.second;
          max_time = max(max_time , t ) ;

          for(int k = 0 ; k < 4;k++ ){
            int new_r = i + r[k];
            int new_c = j + c[k];
            if(new_c >= 0 && new_c < m && new_r >= 0 && new_r < n && vis[new_r][new_c] != 2 && grid[new_r][new_c] == 1){
                  vis[new_r][new_c] = 2 ;
                  q.push({{new_r ,new_c}, t+1});
            }
          }
  
      }
        for(int i = 0; i<n;i++){
        for(int j = 0 ;j<m;j++){
            if(grid[i][j] == 1 &&    vis[i][j] != 2) {
                return -1;
            } 
        }
      }

      return max_time ;

        
    }
};