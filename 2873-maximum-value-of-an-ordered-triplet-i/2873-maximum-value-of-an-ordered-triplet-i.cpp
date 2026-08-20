class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         
         int n = nums.size();
         vector<long long >suff(n,-1);
         int maxi = -1;
         for(int i = n-1;i>=0;i--){
              suff[i] = maxi;
              maxi = max(maxi,nums[i]);
         }

          maxi = nums[0];
           long long maxTri = 0;
         for(int i = 1 ; i<n-1;i++){
            long long cur = 1ll*(maxi-nums[i])*suff[i];
             maxTri = max(maxTri , cur); 
             maxi = max(nums[i],maxi);
         }
         return maxTri;
    }
};