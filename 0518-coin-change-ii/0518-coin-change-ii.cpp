class Solution {
public:

    int change(int amount, vector<int>& coins) {


        int n = coins.size();

        vector<unsigned int>prev(amount+1,0);

        prev[0] = 1;
         
        for(int k = 1; k<= amount;k++){
            if(coins[0] <= k ) prev[k] = prev[k-coins[0]];
        }


        for(int i = 1;i<n;i++){
               vector<unsigned int>cur(amount+1,0);
               cur[0] = 1;
            for(int k = 1;k<=amount;k++){
                if(coins[i] <= k) cur[k] = prev[k]+cur[k-coins[i]];
                else cur[k] = prev[k];
            }
            swap(cur,prev);
        }

        return prev[amount];
 
    }
};