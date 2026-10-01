
class Solution {

    void mergeAndCount(vector<int>& nums, int l, int m, int r) {

        int f = l;
        int s = m + 1;

        vector<int> temp;

        while (f <= m && s <= r) {
            if (nums[f] <= nums[s]) {
                temp.push_back(nums[f]);
                f++;
            } else {

                temp.push_back(nums[s]);
                s++;
            }
        }

        while (f <= m) {
            temp.push_back(nums[f]);
            f++;
        }
        while (s <= r) {
            temp.push_back(nums[s]);
            s++;
        }

        for (int i = 0; i < r - l + 1; i++) {
            nums[l + i] = temp[i];
        }
    }

    long long countPairs(vector<int>& nums, int l, int m, int r) {

        long long pairs = 0;

        int f = l;
        int s = m + 1;

        while (f <= m && s <= r) {

            if (nums[f] <= 2LL * nums[s]) {
                f++;
                continue;
            }

            pairs += m - f + 1;

            s++;
        }

        return pairs;
    }

    long long mergeSort(vector<int>& nums, int l, int r) {

        if (l >= r)
            return 0;
        int m = l + (r - l) / 2;
        long long pairs = mergeSort(nums, l, m);
        pairs += mergeSort(nums, m + 1, r);
        pairs += countPairs(nums, l, m, r);
        mergeAndCount(nums, l, m, r);

        return pairs;
    }

public:
    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};