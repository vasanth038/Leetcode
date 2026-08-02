class Solution {
  
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[0];
        vector<int>dp(n);
      dp[0] = nums[0];
        for(int i = 1;i<n;i++){
             int prev1 = dp[i-1];
             int prev2  = 0 ;
             if(i > 1) prev2 = dp[i-2];
            dp[i] = max(nums[i]+prev2,prev1);
          }

          return dp[n-1];
       
    }
};