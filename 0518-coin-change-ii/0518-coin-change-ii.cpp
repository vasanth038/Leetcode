class Solution {
public:

    int change(int amount, vector<int>& coins) {
       
       int n = coins.size();

       vector<int>prev(amount+1,0);
       prev[0] = 1;
       for(int k = 0;k <= amount ;k++){
        if(coins[0] <= k) prev[k] = prev[k-coins[0]];
       }
  
       for(int i =1 ;i<n;i++){
         vector<int>cur(amount+1,0);
        for(int k = 0 ;k<=amount;k++){
             int nottake = prev[k];
             int take = 0;
             if(coins[i] <= k) take = cur[k-coins[i]];
             cur[k] = take+nottake; 
        }
        prev = cur;
       }

       return prev[amount];
 
    }
};