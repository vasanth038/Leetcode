class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        
        int n = nums.size();

         long long left = 0;
         long long right = 0;

         for(int i = 0;i<n/2;i++) left+=nums[i];
           for(int i = n/2;i<n;i++) right+=nums[i];

         int ans = 0;
         if(left > right) ans++;

         int i = 0;
         int j = n/2;

         for(int k = 1; k < n;k++){
             
              left = left - nums[i] + nums[j];
              right = right - nums[j]+nums[i];
             
             if(left > right) ans++;

              i = (i+1)%n;
              j = (j+1)%n;

         }

         return ans;

    }
};