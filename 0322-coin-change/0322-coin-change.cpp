class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     int n = coins.size();
     vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
     for(int i = 0; i<n;i++) dp[i][0] = 0;
       for(int k = 0;k<=amount;k++){
        if(coins[0] <= k) dp[0][k] = 1+ dp[0][k-coins[0]];
       }
      for(int i = 1;i<n;i++){
         for(int k = 0 ;k <= amount;k++){
             int take = 1e9;
             int nottake = dp[i-1][k];
             if(coins[i] <= k) take = 1+dp[i][k-coins[i]];
             dp[i][k] = min(take,nottake);
         }
      }

      if(dp[n-1][amount] < 1e9) return dp[n-1][amount];
      return -1;

        
    
    }
};