class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       vector<vector<int>>dp(n+1,vector<int>(2,0));
         for(int i = n-1 ; i>=0;i--){
             for(int k = 0;k<=1;k++){
                if(k){
                      int buyNow = -prices[i]+dp[i+1][0];
                      int buyNext = dp[i+1][1];
                      dp[i][k] = max(buyNow,buyNext);
                }
                else{
                     int sell = prices[i]+dp[i+1][1];
                     int notSell = dp[i+1][0];
                     dp[i][k] = max(sell,notSell);
                }
             }
         }

         return dp[0][1];
        
    }
};