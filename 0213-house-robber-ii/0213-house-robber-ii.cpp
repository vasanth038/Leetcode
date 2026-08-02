class Solution {

     int helper(vector<int>&nums,int start,int end,vector<vector<int>>&dp){
         if(start > end) return 0;
         if(dp[start][end] != -1) return dp[start][end];
          int take = nums[end]+helper(nums,start,end-2,dp);
          int leave = helper(nums,start,end-1,dp);
          return dp[start][end] =  max(leave,take);
     }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       int first = helper(nums,0,n-2,dp);
   vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
    int last = helper(nums,1,n-1,dp2);
       return max(first,last);
    }
};