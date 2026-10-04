class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int last = 0;
        int req = k;

        for (auto x : arr) {
            int m = x - last - 1;
            if (m >= req)  return last + req;
            
            req -= m;
            last = x;
        }

        return last + req;
    }
};