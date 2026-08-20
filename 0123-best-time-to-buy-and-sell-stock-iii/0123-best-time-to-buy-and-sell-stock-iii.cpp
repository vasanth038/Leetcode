class Solution {

     int helper(vector<int>& prices , int i , int buy,int trs,vector<vector<vector<int>>>&dp){
         int n = prices.size();
         if(i >= n || trs >= 2) return 0;
         int profit = 0;
          if(dp[i][buy][trs] != -1) return dp[i][buy][trs];
         if(buy){
              int buyNow = -prices[i]+helper(prices,i+1,0,trs,dp);
              int buyNext = helper(prices,i+1,1,trs,dp);
              profit = max(buyNow,buyNext);
         }
         else{

            int sellNow =  prices[i]+helper(prices,i+1,1,trs+1,dp);
             int sellNext = helper(prices,i+1,0,trs,dp);
         profit = max(sellNow,sellNext);
             
         }

         return dp[i][buy][trs] = profit;


     }
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
         vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
       return helper(prices,0,1, 0,dp); 
    }
};