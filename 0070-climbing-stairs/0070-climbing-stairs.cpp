class Solution {
public: 
    int climbStairs(int n) {
       
       
       int d1 = 1;
        int d2 = 1;
       for(int i = 2; i <= n;i++){
           int c = d1+d2;
            d2 = d1;
            d1 = c;
       }

       return d1;
 
    }
};