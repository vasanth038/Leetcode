class Solution {
public:
      
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
         nums.push_back(1);
         nums.insert(nums.begin(),1);
         vector<vector<int>>dp(n+2,vector<int>(n+2,0));

         for(int i = n;i>=1;i--){

            for(int j = 1;j<=n;j++){
                if(i > j) continue;

                int coins = 0;
                for(int k = i ; k <= j ;k++){
                    int cur = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1]+dp[k+1][j];
                    coins = max(coins,cur);
                }
                dp[i][j] = coins;
            }
         }


        return dp[1][n];
    }
};