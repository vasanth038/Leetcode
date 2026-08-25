#include<bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
       int n = nums.size();

       int suff = 1;
       int pref = 1;
       int maxP = -1e9;

       for(int i = 0 ; i <n;i++){
          pref*=nums[i];
          maxP = max(maxP,pref);
          if(pref == 0) pref = 1;
       }
       for(int i = n-1 ; i >=0;i--){
          suff*=nums[i];
          maxP = max(maxP,suff);
          if(suff == 0) suff = 1;
       }


       return maxP;
          
    }
};
