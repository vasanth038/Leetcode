class Solution {
public:
    int helper(vector<int>& nums, int d) {

        int sum = 0;

        for (int x : nums) {
            sum += (x + d - 1) / d;
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int maxi = *max_element(nums.begin(), nums.end());
       
        int n = nums.size();
        int l = 1;
        int r = maxi;
        int ans = 0;
        while (l <= r) {

            int m = l + (r - l) / 2;
            int sum = helper(nums, m);
            if (sum <= threshold) {
                ans = m;
                r = m - 1;
            } else
                l = m + 1;
        }

        return ans;
    }
};