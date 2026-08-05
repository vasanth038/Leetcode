class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
         int t = sum/2;
         vector<vector<bool>>dp(n,vector<bool>(t+1,false));

         for(int i = 0;i<n;i++){
             dp[i][0] = true;
         }
         if(nums[0] <= t) dp[0][nums[0]] = true;

         for(int i = 1;i<n;i++){
            for(int k = 1;k<=t;k++){
                bool take = false;
                bool notTake = dp[i-1][k];
                if(nums[i] <= k) take = dp[i-1][k-nums[i]];
                dp[i][k] = take || notTake;
            }
         }
         return dp[n-1][t];

    }
};