class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
          
          int curMax = 0;
          int curMin = 0;
          int maxSum = -1e9;
          int minSum = 1e9;
          int total = 0;
          for(int i = 0;i<n;i++){
          
          curMax+=nums[i];
          maxSum = max(maxSum,curMax);
          if(curMax < 0) curMax = 0;

          curMin +=nums[i];
          minSum = min(minSum,curMin);
          if(curMin > 0) curMin  = 0; 
          total+=nums[i];
          }
          if(total - minSum == 0) return maxSum;

          return max(maxSum , total-minSum);
        

    }
};