class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>prev1(2,0);
         vector<int>prev2(2,0);

        for(int i = n-1;i>=0;i--){
            vector<int>cur(2,0);
              for(int buy = 0 ;buy <= 1;buy++){
                 if(buy){
                     int buyNow = -prices[i] + prev1[0];
                     int buyNext = prev1[1];
                     cur[buy] = max(buyNow,buyNext);
                 }
                 else{
                     int sellNow = prices[i]+prev2[1];
                     int sellNext = prev1[0];
                     cur[buy] = max(sellNow,sellNext);
                 }
              }
              
              swap(prev2, prev1);
              swap(prev1, cur);
        }
        return prev1[1];
    }
};