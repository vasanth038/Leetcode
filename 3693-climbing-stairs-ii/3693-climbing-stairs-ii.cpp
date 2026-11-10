class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        int l1 = 0;
        int l2 = 0;
        int l3 = 0;
        for (int i = 0; i < n; i++) {
            int c = min({costs[i] + 4 + l2, costs[i] + 1 + l1, costs[i] + 9 + l3});
            l3 = l2;
            l2 = l1;
            l1 = c;
        }

        return l1;
    }
};