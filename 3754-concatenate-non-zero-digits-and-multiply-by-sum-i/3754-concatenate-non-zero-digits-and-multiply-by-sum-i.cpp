class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long sum = 0;
        long long x = 0;
        int r = 1;
        while(n > 0){
            long long d = n%10;
             n/=10;
             if(d == 0)  continue;
             x= x+d*r;
             sum+=d;
             r*=10;

        }
        return x*sum;

    }
};