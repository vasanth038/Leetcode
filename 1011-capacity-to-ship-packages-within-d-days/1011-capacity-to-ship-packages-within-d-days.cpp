class Solution {

private:
    int findDays(vector<int>& weights, int cap) {

        int days = 0;

        int totalWt = 0;

        for (auto wt : weights) {

            if (totalWt + wt > cap) {
                days++;
                totalWt = wt;
            } else
                totalWt += wt;
        }

        return days + 1;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {

        long long totalWt = 0;
        for (auto x : weights)
            totalWt += x;

        int maxi = *max_element(weights.begin(), weights.end());

        int l = maxi;
        int r = totalWt;
        int ans = totalWt;

        while (l <= r) {

            int m = l + (r - l) / 2;

            int daysTaken = findDays(weights, m);

            if (daysTaken <= days) {
                ans = m;
                r = m - 1;
            } else
                l = m + 1;
        }

        return ans;
    }
};