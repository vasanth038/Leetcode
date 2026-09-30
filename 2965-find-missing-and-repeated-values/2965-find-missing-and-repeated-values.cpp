#include <bits/stdc++.h>
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        long n = grid.size();
        n = n * n;
        long long s1 = n * (n + 1);
        s1 = s1 / 2;

        long long sq1 = n * (n + 1) * (2 * n + 1);
        sq1 /= 6;

        long long s2 = 0;
        long long sq2 = 0;

        for (int i = 0; i < grid.size(); i++) {
           for(int j = 0;j<grid.size();j++){

             s2 += grid[i][j] ;

            sq2 += (grid[i][j] * grid[i][j]);

           }
        }

        int v1 = s1 - s2;
        int v2 = sq1 - sq2;

        int x = (v2 / v1 ) +  v1;
        x = x/2;
        int y = x - v1;
      
        return {y, x};
    }
};