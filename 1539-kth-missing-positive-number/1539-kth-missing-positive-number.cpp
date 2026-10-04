class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int last = 0;
        while (l <= r) {

            int m = l + (r - l) / 2;
            int totalMiss = arr[m] - m - 1;

            if (totalMiss < k) {
                last = m+1;
                l = m + 1;
            } else
                r = m - 1;
        }

        return last + k;
    }
};