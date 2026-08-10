class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
     int n = nums.size();
    int sum = accumulate(nums.begin(),nums.end(),0);
    if( sum-target < 0 || (sum-target)%2 != 0) return 0;
    int t = (sum-target)/2;
      vector<int>prev(t+1,0);
     prev[0] = 1;
     if(nums[0] <= t ) prev[nums[0]]++;
        for(int i =1;i<n;i++){
            vector<int>cur(t+1,0);
             for(int k = 0;k<=t;k++){
                int nottake = prev[k];
                int take = 0;
                if(nums[i] <= k) take = prev[k-nums[i]];
                cur[k] = take+nottake;
             }
          prev = cur;
        }

        return prev[t];
}    
};