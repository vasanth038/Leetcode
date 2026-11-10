class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        int l1 = 0;
        int l2 = 0;
        int l3 = 0;
        for (auto cost : costs) {
            int c = min({cost + 4 + l2, cost + 1 + l1, cost + 9 + l3});
            l3 = l2;
            l2 = l1;
            l1 = c;
        }

        return l1;
    }
};