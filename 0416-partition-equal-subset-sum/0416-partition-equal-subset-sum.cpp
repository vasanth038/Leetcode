class Solution {
public:
    bool canPartition(vector<int>& nums) {
      
      int n = nums.size();

      int sum = accumulate(nums.begin(),nums.end(),0);
      if(sum%2 != 0) return false;

      int s = sum/2;

      vector<bool>prev(s+1,false);
            prev[0] = true;
      if(nums[0] <= s) prev[nums[0]] = true;
       for(int i = 1;i<n;i++){
           vector<bool>cur(s+1,false);
        for(int k = 0 ;k<=s;k++ ){
            if(nums[i] <= k) cur[k] = prev[k] || prev[k-nums[i]];
            else cur[k] = prev[k];
             
        }
        swap(cur,prev);
       }
      return prev[s];
    }
};