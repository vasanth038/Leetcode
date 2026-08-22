class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
         long long p = 1;
         long long digSum = 0;

         while(x){
             int r = x%10;
             p*=r;
             digSum +=r;

             x/=10;
         } 

         long long sum = p+digSum;
         return (n%sum == 0);
    }
};