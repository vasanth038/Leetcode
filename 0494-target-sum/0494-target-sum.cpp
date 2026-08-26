class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum-target < 0 || (sum-target)%2 == 1) return 0;
    int n = nums.size();
    // s1+s2 == sum , s1-s2 == target , (sum-target)%2 == 0 && >=0 
    // when last one element is left if(target == 0) ||  nums[0] == target return 1;
    // 2 choice take or nottake : helper(i-1,target-nums[i]) ,helper(i-1,target);
      
       int s =  (sum-target)/2 ;
    vector<vector<int>>dp(n,vector<int>(s+1,0));

    dp[0][0] = 1;
    if(nums[0] <= s) dp[0][nums[0]] += 1;

    for(int i = 1;i<n;i++){

        for(int j = 0;j<=s;j++){
            if(nums[i] <= j) dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i]];
            else dp[i][j] = dp[i-1][j];
        }
    }



return dp[n-1][s];
    
}    
};