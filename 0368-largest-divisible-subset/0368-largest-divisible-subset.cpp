class Solution {
public:
        
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n = nums.size();
           vector<int>dp(n,1);
           sort(nums.begin(),nums.end());
           for(int i = 0;i<n;i++){
            for(int p = 0;p<i;p++){
                  if( nums[i]%nums[p] == 0 || nums[p]%nums[i] == 0 ){
                    dp[i] = max(dp[i] , dp[p]+1);
                  }
             }
           }
             
         int idx = max_element(dp.begin(),dp.end())-dp.begin();
         int c = dp[idx];
         vector<int>ans;
         int p = idx;
         while(c > 0 && idx >= 0){
             if(dp[idx] == c && (nums[idx]%nums[p] == 0 || nums[p]%nums[idx] == 0) ){
                   p = idx;
                ans.push_back(nums[idx]);
                c--;
             }
             idx--;

         }

         return ans ;

    }
};