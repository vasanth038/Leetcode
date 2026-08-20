class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       int minPrice = 1e9;
        
        for(int price : prices){
          minPrice = min(minPrice,price);
          profit = max(profit,price-minPrice);
        }

        return profit;
    }
};