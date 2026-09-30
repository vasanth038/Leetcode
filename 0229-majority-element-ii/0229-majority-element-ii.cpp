class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int n = nums.size();
        for (auto x : nums) {

            if (ele1 == x)
                cnt1++;
            else if (ele2 == x)
                cnt2++;
            else if (cnt1 == 0) {
                ele1 = x;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                ele2 = x;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;

        cnt1 = 0, cnt2 = 0;

        for (auto x : nums) {
            if (x == ele1)
                cnt1++;
            else if (x == ele2)
                cnt2++;
        }

        if (cnt1 > n / 3)
            ans.push_back(ele1);
        if (cnt2 > n / 3)
            ans.push_back(ele2);

        return ans;
    }
};