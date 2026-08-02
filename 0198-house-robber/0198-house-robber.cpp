class Solution {
  
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
         int prev1 = 0;
         int prev2 = 0;
        for(int i = 0;i<n;i++){
            int cur = max(nums[i]+prev2,prev1);
            prev2 = prev1;
            prev1 = cur;

          }

          return prev1;
       
    }
};