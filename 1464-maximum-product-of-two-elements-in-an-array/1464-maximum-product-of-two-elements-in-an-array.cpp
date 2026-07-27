class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        for(int x : nums){
             if(x >= mx1){
                mx2 = mx1;
                mx1 = x;
             }
             else mx2 = max(mx2,x);
        }
        mx1--;
        mx2--;

        return mx1*mx2;
   } 
};