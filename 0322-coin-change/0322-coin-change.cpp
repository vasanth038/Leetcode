class Solution {
  int   helper(vector<int>&coins ,int i,int amount, vector<vector<int>>&dp){
         if(i < 0 ) return 1e9;
         if(amount == 0) return 0;
         if(dp[i][amount] != -1) return dp[i][amount];
         int take = 1e9;
          if(coins[i] <= amount)  take = 1+ helper(coins , i , amount-coins[i],dp) ;
          int nottake = helper(coins,i-1,amount,dp); 

          return dp[i][amount] = min(take,nottake);
     }
public:
    int coinChange(vector<int>& coins, int amount) {
     int n = coins.size();
     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
      int ans = helper(coins,n-1,amount,dp);
      if(ans >= 1e9) return -1;
      
      return ans;
    
    }
};