class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        int n = queries.size();
        vector<int> freq;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) freq.push_back(i);
        }

        vector<int> ans(n, -1);

        for (int q = 0; q < n; q++) {

            int f = queries[q];

            if (f <= freq.size()) ans[q] = freq[f - 1];
        }

        return ans;
    }
};