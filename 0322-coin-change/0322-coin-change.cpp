class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
      int n = coins.size();
 
        vector<int>prev(amount+1,1e9);
        prev[0] = 0;
       for(int k = 1 ;k <= amount;k++){
             if(coins[0] <= k) prev[k] = 1+prev[k-coins[0]];
       }

         for(int i = 1;i<n;i++){
              vector<int>cur(amount+1,1e9);
                cur[0] = 0;
              for(int k = 1 ;k <= amount;k++){
                     cur[k] = prev[k];
                      if(coins[i] <= k){
                       cur[k] = min(cur[k] ,  1+cur[k-coins[i]] ) ;
                 }
            }
            swap(cur,prev);
         }
     
         int ans = prev[amount];
      return (ans >= 1e9 ? -1 : ans);
        
    
    }
};