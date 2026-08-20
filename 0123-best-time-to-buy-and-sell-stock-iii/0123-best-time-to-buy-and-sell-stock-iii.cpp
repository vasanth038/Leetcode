class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
       vector<vector<int>>prev(3,vector<int>(2,0));
          for(int i = n-1; i >=0;i--){
               vector<vector<int>>cur(3,vector<int>(2,0));
             for(int t = 0 ; t <= 1 ; t++){
                for(int k = 0;k<=1;k++){
                   if(k){
                     int buyNow = -prices[i]+prev[t][0];
                     int buyNext = prev[t][1];
                     cur[t][k] = max(buyNow,buyNext);
                   }
                   else{
                     
               int sellNow =  prices[i]+prev[t+1][1];
                int sellNext = prev[t][0];
                cur[t][k] = max(sellNow,sellNext);
                   }
                   
                }
             }
             swap(cur,prev);
          }

          
       return prev[0][1]; 
    }
};