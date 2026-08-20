class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
          for(int i = n-1; i >=0;i--){
             for(int t = 0 ; t <= 1 ; t++){
                for(int k = 0;k<=1;k++){
                   if(k){
                     int buyNow = -prices[i]+dp[i+1][t][0];
                     int buyNext = dp[i+1][t][1];
                     dp[i][t][k] = max(buyNow,buyNext);
                   }
                   else{
                     
               int sellNow =  prices[i]+dp[i+1][t+1][1];
                int sellNext = dp[i+1][t][0];
                dp[i][t][k] = max(sellNow,sellNext);
                   }
                   
                }
             }
          }

          
       return dp[0][0][1]; 
    }
};