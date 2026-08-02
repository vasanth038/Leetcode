class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[0];
         vector<int>dp1(n,0);
         for(int i = 0;i<n-1;i++){
             int prev1 = 0;
              int prev2 = 0; 
            if(i > 0) prev1 = dp1[i-1];
            if(i > 1) prev2 = dp1[i-2];
              dp1[i] = max(nums[i]+prev2 , prev1);
         }
         vector<int>dp2(n,0);
         for(int i = 1;i<n;i++){
             int prev1 = 0;
              int prev2 = 0; 
            if(i > 1) prev1 = dp2[i-1];
            if(i > 2) prev2 = dp2[i-2];
              dp2[i] = max(nums[i]+prev2 , prev1);
         }
         return max(dp1[n-2],dp2[n-1]);

    }
};