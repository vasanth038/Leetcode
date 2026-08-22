class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
    

      vector<int>dp(n,1);
         
         dp[0] = 1;
      for(int i = 0;i<n;i++){
        for(int p = 0;p <i;p++){
            if(nums[i] > nums[p]) dp[i] = max(dp[p]+1,dp[i]);
        }
      }
      return *max_element(dp.begin(),dp.end());
    }
};