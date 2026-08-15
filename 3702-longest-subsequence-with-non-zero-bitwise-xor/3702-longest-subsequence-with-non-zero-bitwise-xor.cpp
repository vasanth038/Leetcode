class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        sort(nums.rbegin(),nums.rend());
       if(nums[0] == 0) return 0;
        vector<long long >bits(31,0);
        for(int n : nums){
             int p = 0;
             while(n > 0){
                 if(n&1){
                     bits[p]++;
                 }
                 p++;
                 n = n >> 1;
             }
        }

        int n = nums.size();
        long long odd = 0;
        long long even = 0;
        for(int i = 30 ; i>=0;i--){
             if(bits[i] == 0) {
                continue;
             }
             if(bits[i]&1){
                 odd++;
                 break;
             }
             else {
                even++;
             }
        }
        if(odd) return n;
      return n - 1;
    }
};