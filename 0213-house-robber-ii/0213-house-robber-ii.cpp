class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[0];
           int prev1 = 0;
            int prev2 = 0; 
         for(int i = 0;i<n-1;i++){
              int cur = max(nums[i]+prev2,prev1);
              prev2 =prev1;
              prev1 = cur;
         }
           int ans = prev1;
           prev1 = 0;
           prev2 = 0;
         for(int i = 1;i<n;i++){
               int cur = max(nums[i]+prev2,prev1);
              prev2 =prev1;
              prev1 = cur;
         }
         ans = max(ans,prev1);
         return ans;

    }
};