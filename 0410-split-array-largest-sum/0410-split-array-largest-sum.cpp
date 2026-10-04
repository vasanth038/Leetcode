class Solution {

    bool valid(vector<int>& nums, int cap, int k) {

        int sum = 0;

        for (int x : nums) {

            if (sum + x > cap) {
                sum = x;
                k--;
            } else
                sum += x;
        }

        return k >= 1;
    }

public:
    int splitArray(vector<int>& nums, int k) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxi = *max_element(nums.begin(), nums.end());

        int l = maxi;
        int r = sum;
        int ans = sum;

        while (l <= r) {

            int m = l + (r - l) / 2;
            if (valid(nums, m, k)) {
                ans = m;
                r = m - 1;
            } else
                l = m + 1;
        }

        return ans;
    }
};