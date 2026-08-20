class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int>prev(2,0);

        for(int i = n-1;i>=0;i--){
             vector<int>cur(2,0);
                     int buyNow = -prices[i]-fee+prev[0];
                     int buyNext = prev[1];
                    int sellNow = prices[i]+prev[1];
                    int sellNext = prev[0];

                    
                     cur[1] = max(buyNext,buyNow);
                    cur[0] = max(sellNow , sellNext);
             swap(cur,prev);
        }

        return prev[1];

    }
};