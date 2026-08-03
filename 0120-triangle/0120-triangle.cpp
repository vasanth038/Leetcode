class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
          vector<int>next(n,0);
           for(int i = n-1;i>=0;i--){
            vector<int>cur(n,0);
               for(int j = i ; j >= 0;j--){
                if(i == n-1) cur[j] = triangle[i][j];
                else {
                    cur[j] = triangle[i][j]+min(next[j],next[j+1]);
                }
               }
               next = cur;
           }
           return next[0];
    }
};