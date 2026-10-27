class Solution {

public:
    double helper(double base, long long exp) {

        if (exp <= 0)  return 1;
        if (exp & 1) return helper(base, exp - 1) * base;
        else return helper(base * base, exp / 2);
    }
    double myPow(double x, int n) {

        if (n < 0){
           return 1.0 / helper(x, (long long ) -1*n);
        }
           
        return helper(x, n);
    }
};