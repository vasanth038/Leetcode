class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k != 0) return false;

        int s = sum/k;
        int N = 1 << n;
        vector<int>dp(N,-1);
        dp[0] = 0;

        for(int mask = 0 ; mask < N; mask++){
            if(dp[mask] == -1) continue;

            for(int i = 0;i<n;i++){

                 if( mask & (1 << i) ) continue;

                 if(dp[mask]+nums[i] > s ) continue;
                 
                 int newMask = mask | ( 1 << i);
                 dp[newMask] = (dp[mask]+nums[i])%s;

            }
        }

        return dp[N-1] == 0;

    }
};