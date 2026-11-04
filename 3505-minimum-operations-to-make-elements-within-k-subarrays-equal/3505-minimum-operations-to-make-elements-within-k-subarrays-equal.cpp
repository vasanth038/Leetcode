class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long > cost;
        long long sumLow = 0, sumHigh = 0;
        int n = nums.size();
        multiset<int> low, high;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                int val = *it;
                low.erase(it);
                high.insert(val);
                sumLow -= val;
                sumHigh += val;
            }
            while (low.size() < high.size()) {
                auto it = high.begin();
                int val = *it;
                high.erase(it);
                low.insert(val);
                sumLow += val;
                sumHigh -= val;
            }
        };

        for (int i = 0; i < n; i++) {

            int val = nums[i];
            if (low.empty() || val <= *low.rbegin()) {
                sumLow += val;
                low.insert(val);
            } else {
                sumHigh += val;
                high.insert(val);
            }

            if (i >= x) {
                int rem = nums[i - x];
                auto it1 = low.find(rem);
                if (it1 != low.end()) {
                    int val = *it1;
                    low.erase(it1);
                    sumLow -= val;
                }

                else {

                    auto it2 = high.find(rem);
                    int val = *it2;
                    high.erase(it2);
                    sumHigh -= val;
                }
            }

            balance();

            if (i >= x - 1) {

                auto median = *low.rbegin();

                long long op = low.size() * median - sumLow + sumHigh -
                         median * high.size();

                cost.push_back(op);
            }
        }

        long long INF = LLONG_MAX;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
};