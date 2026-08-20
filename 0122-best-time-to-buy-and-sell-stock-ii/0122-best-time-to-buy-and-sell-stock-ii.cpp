class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
          vector<int>prev(2,0);
         for(int i = n-1 ; i>=0;i--){
             vector<int>cur(2,0);
             for(int k = 0;k<=1;k++){
                if(k){
                      int buyNow = -prices[i]+prev[0];
                      int buyNext = prev[1];
                      cur[k] = max(buyNow,buyNext);
                }
                else{
                     int sell = prices[i]+prev[1];
                     int notSell = prev[0];
                     cur[k] = max(sell,notSell);
                }
         }
           swap(cur,prev);
         }

         return prev[1];
        
    }
};