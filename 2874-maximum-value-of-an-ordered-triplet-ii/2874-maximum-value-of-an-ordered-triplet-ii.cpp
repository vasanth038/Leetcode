class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>suff(n,0);
          int maxi_right = 0;
        for(int i = n-1;i>0;i--){
            suff[i] = maxi_right;
            maxi_right = max(maxi_right,nums[i]);
        }
      long long ans = 0 ;
        int left_max = nums[0];
        for(int i = 1;i<n-1;i++){
           long long cur = 1LL*(left_max - nums[i])*suff[i];
           ans = max(ans,cur);
           left_max = max(left_max,nums[i]);
        } 

        return ans;
    }
};