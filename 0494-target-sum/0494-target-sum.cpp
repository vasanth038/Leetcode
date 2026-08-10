class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
     int n = nums.size();
    int sum = accumulate(nums.begin(),nums.end(),0);
    if( sum-target < 0 || (sum-target)%2 != 0) return 0;
    int t = (sum-target)/2;
     vector<vector<int>>dp(n,vector<int>(t+1,0));
     dp[0][0] = 1;
     if(nums[0] <= t ) dp[0][nums[0]]++;
        for(int i =1;i<n;i++){
             for(int k = 0;k<=t;k++){
                int nottake = dp[i-1][k];
                int take = 0;
                if(nums[i] <= k) take = dp[i-1][k-nums[i]];
                dp[i][k] = take+nottake;
             }
        }

        return dp[n-1][t];
}    
};