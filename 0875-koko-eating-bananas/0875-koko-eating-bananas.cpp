class Solution {

private:
    int helper(vector<int>& piles, int m,int h) {

        int time = 0;

        for (auto p : piles) {

            time += (p + m - 1) / m;

            if(time > h) break;
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = *max_element(piles.begin(), piles.end());

        int l = 1;
        int r = maxi;

        int ans = maxi;

        while (l <= r) {
            int m = l + (r - l) / 2;

            int time = helper(piles, m , h);

            if (time <= h) {
                ans = m;
                r = m - 1;
            } else{
                 l = m + 1;
            }
               
        }

        return ans;
    }
};