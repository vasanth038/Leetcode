class Solution {
public:
    long long countCommas(long long n) {
       
        long long ans = 0;
         
         long long x = 999;

         while(x < n){
            ans+=(n-x);
            x = x*1000 + 999;
         }

         return ans;
         
    }
};