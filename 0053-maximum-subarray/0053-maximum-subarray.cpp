class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = -1e9;
        int n = nums.size();
        int cur = 0;
        for (int i = 0; i < n; i++) {

            cur = max(cur + nums[i], nums[i]);
            maxSum = max(maxSum, cur);
        }

        return maxSum;
    }
};