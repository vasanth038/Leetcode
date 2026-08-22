class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i = n-1;i>=0;i--){
             
             for(int p = -1;p<i;p++){
                if(p == -1 || nums[i] > nums[p]){
                     dp[i][p+1] = max(1+dp[i+1][i+1] , dp[i][p+1]);
                }
                dp[i][p+1] = max(dp[i][p+1] , dp[i+1][p+1]);
             }
        }

        return dp[0][0];


        
    }
};