class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;
        int maxi = 0;
       int l = 0;
       for(int r = 0 ;r<n;r++){
         mpp[nums[r]]++;

         while(l <= r && mpp[nums[r]] > k ){
               mpp[nums[l]]--;
               l++;
         }
         maxi = max(maxi, r-l+1);
       }

       return maxi;

    }
};