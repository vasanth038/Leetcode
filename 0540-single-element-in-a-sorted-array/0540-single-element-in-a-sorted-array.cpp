class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {

            int m = l + (r - l) / 2;

            bool left = false;
            bool right = false;
            
            if (m > 0 && nums[m - 1] == nums[m])
                left = true;
            if (m + 1 < n && nums[m + 1] == nums[m])
                right = true;
            if (!left && !right)
                return nums[m];

            if (right)
                m++;

            int l1 = m - l + 1;
            int l2 = r - m;

            if (l1 % 2)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};