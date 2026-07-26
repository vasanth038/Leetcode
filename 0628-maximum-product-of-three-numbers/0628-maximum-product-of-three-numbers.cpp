class Solution {
public:
    int maximumProduct(vector<int>& nums) {
          int min1 = INT_MAX;
          int min2 = INT_MAX;
          int mx1 = INT_MIN;
           int mx2 = INT_MIN;
            int mx3 = INT_MIN;

            for(int x : nums){
                 if(x <= min1){
                    min2 = min1;
                    min1 = x;
                 }
                 else min2 = min(min2,x);
            }
              for(int x : nums){
                 if(x >= mx1){
                    mx3 = mx2;
                    mx2 = mx1;
                    mx1 = x;
                 }
                 else if( x >= mx2 ){
                     mx3 = mx2;
                    mx2 = x ;
                 }
                 else mx3 = max(mx3,x);
            }

            long long p = mx1*mx2;
            p*=mx3;
           long long  n = min1*min2;
           n*=mx1;
        return int(max(p,n));
    }
};