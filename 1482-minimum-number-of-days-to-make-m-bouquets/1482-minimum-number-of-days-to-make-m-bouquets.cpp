class Solution {

private:
    int helper(vector<int>& bloomDay, int mid, int k) {

        int str = 0;
        int boq = 0;

        for (auto b : bloomDay) {

            if (b <= mid)
                str++;
            else
                str = 0;

            if (str == k) {
                boq++;
                str = 0;
            }
        }

        return boq;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();
        long long req = 1LL*m * k;
        if (n < req)
            return -1;

        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int mini = *min_element(bloomDay.begin(), bloomDay.end());

        int l = mini;
        int r = maxi;
        int ans = -1;
        while (l <= r) {

            int mid = l + (r - l) / 2;

            int boq = helper(bloomDay, mid, k);

            if (boq >= m) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return ans;
    }
};