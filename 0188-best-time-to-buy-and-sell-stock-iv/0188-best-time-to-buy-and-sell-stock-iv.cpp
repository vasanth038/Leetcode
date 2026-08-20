class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>>prev(k+1, vector<int>(2,0));
        for(int i = n-1;i>=0;i--){
             vector<vector<int>>cur(k+1, vector<int>(2,0));
             for(int t = 1 ; t <= k;t++){
                 for(int buy = 0;buy<=1;buy++){
                    if(buy){
                         int buyNow = -prices[i]+prev[t][0];
                         int buyNext = prev[t][1];
                         cur[t][buy] = max(buyNow,buyNext);
                    }
                    else{
                         int sellNow = prices[i]+prev[t-1][1];
                         int sellNext = prev[t][0];
                         cur[t][buy] = max(sellNow,sellNext);
                    }
                 }
             }
             swap(prev,cur);
        }

        return prev[k][1];
    }
};