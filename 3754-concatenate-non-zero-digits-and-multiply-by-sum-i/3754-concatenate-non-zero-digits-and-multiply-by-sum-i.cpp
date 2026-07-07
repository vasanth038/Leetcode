class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long sum = 0;
        long long y = 0;
        while(n > 0){
            long long rem = n%10;
             if(rem > 0) y= y*10+rem;
             sum+=rem;
             n/=10;

        }
         long long x = 0;
         while(y > 0){
            long long rem = y%10;
           x= x*10+rem;
            
             y/=10;

        }
        return x*sum;

    }
};