class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int odd = 0 , even =  0 ,ans = 0 ,mod = 1e9 + 7;

        for (int x : arr) {

            if (x % 2 == 1) {

                swap(odd, even);
                odd++;
            } else
                even++;
            ans = (ans + odd) % mod;
        }
        return ans;
    }
};