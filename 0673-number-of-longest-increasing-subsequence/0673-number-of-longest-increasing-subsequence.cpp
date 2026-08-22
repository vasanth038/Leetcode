class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>ways(n,1);
        for(int i = 0;i<n;i++){
             int w = 1;
            for(int p = 0;p<i;p++){
                if(nums[i] > nums[p]){
                 if(dp[i] == dp[p]+1){
                    w+=ways[p];
                  }
                  if(dp[i] < dp[p]+1){
                      dp[i] = dp[p]+1;
                     w = ways[p];
                  }
                }
            }
            ways[i] = w;
        } 

     int log = *max_element(dp.begin(),dp.end());
    int totalWays = 0;
     for(int i = 0;i<n;i++){
        if(dp[i] == log){
             totalWays+=ways[i];
        }
     }

     return totalWays;

    }
};