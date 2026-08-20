class Solution {
public:
     int helper(vector<int>& nums,int ind,int last_ind ,vector<vector<int>>&dp){
        int n = nums.size();
        if(ind == n ) return 0;
        if(dp[ind][last_ind+1] != -1) return dp[ind][last_ind+1];
        int check = 0;
         if(last_ind == -1 || nums[ind] > nums[last_ind]){
             check =  1+helper(nums,ind+1,ind,dp);
         }
          int skip = helper(nums,ind+1,last_ind,dp);

        return dp[ind][last_ind+1] = max(check,skip);
          
     }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return helper(nums,0 , -1,dp); 
    }
};