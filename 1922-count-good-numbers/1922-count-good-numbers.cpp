class Solution {
public:
    const int mod = 1e9 + 7;

    long long helper(long long base, long long exp) {

        long long res = 1;
        base = base % mod;
        while (exp > 0) {

            if (exp & 1) {
                res = (res * base) % mod;
            }

            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {

        long long even = helper(5, (n + 1) / 2);
        long long odd = helper(4, n / 2);
        return (even * odd) % mod;
    }
};
