class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int dec = 1, inc = 1;
        int longest = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] > nums[i - 1])
                inc++;
            else
                inc = 1;
            if (i > 0 && nums[i] < nums[i - 1])
                dec++;
            else
                dec = 1;
            longest = max({longest, inc, dec});
        }

        return longest;
    }
};