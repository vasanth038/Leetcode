#include<bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
       int n = nums.size();

       int minP = 1;
       int maxP= 1;
       int maxAns = -1e9;
         
         for(int i = 0;i<n;i++){

            if(nums[i] < 0){
                swap(maxP,minP);
            }
            maxP *= nums[i];
            minP *= nums[i];
             maxAns = max(maxAns , maxP);
            if(maxP <= 0) maxP = 1;
            if(minP == 0) minP = 1;
         }
       


       return maxAns;
          
    }
};
