class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
            int m = cuts.size();
           cuts.push_back(n);
           cuts.push_back(0);
           sort(cuts.begin(),cuts.end());

           vector<vector<int>>dp(m+2,vector<int>(m+2));

           for(int i = m ; i>=1;i--){

            for(int j = 1;j<=m;j++){
                if(i > j) continue;

                int cost = 1e9;

                for(int k = i ; k<=j;k++){
                    int cur = (cuts[j+1] - cuts[i-1])+dp[i][k-1]+dp[k+1][j];
                    cost = min(cost ,cur);
                }
               dp[i][j] = cost;
            }
           }

           return dp[1][m];
    }
};