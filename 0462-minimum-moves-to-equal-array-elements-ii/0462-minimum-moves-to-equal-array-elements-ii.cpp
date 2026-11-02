class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int t = nums[n / 2];
        int moves = 0;

        for (auto x : nums)
            moves += abs(x - t);

        return moves;
    }
};