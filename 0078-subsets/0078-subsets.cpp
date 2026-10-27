class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& cur,
                vector<vector<int>>& ans) {

        if (i >= nums.size()) {
            ans.push_back(cur);
            return;
        }

        helper(i + 1, nums, cur, ans);

        cur.push_back(nums[i]);
        helper(i + 1, nums, cur, ans);
        cur.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> cur;
        vector<vector<int>> ans;
        helper(0, nums, cur, ans);
        return ans;
    }
};