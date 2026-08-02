class Solution {
    private:
      int helper(vector<int>&nums,int i,vector<int>&dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i]+helper(nums,i-2,dp);
        int leave = helper(nums,i-1,dp);
        return dp[i] = max(take,leave);
      }
  
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
       return helper(nums,n-1,dp);
    }
};