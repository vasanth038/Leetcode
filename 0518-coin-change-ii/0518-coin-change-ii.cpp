class Solution {
public:

    int change(int amount, vector<int>& coins) {


        int n = coins.size();

        vector<unsigned int>prev(amount+1,0);
        prev[0] = 1;
        for(int i = 1;i<=n;i++){ 
            for(int k = 1;k<=amount;k++){
                if(coins[i-1] <= k) prev[k] += prev[k-coins[i-1]];
            }
        }

        return prev[amount];
 
    }
};