class Solution {
         int helper(vector<int>&stoneValue,int i,vector<int>&dp){
             int n = stoneValue.size();
             if(i >= n ) return 0;
             if(dp[i] != -1) return dp[i];
             int take1 = stoneValue[i] - helper(stoneValue,i+1,dp);
             int take2 = INT_MIN;
             int take3 = INT_MIN;
           if(i+1 < n)   take2 = stoneValue[i]+stoneValue[i+1] - helper(stoneValue,i+2,dp);
            if(i+2 < n)  take3 = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - helper(stoneValue,i+3,dp);
            return dp[i] = max(take1,max(take2,take3));

         }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n,-1);
        int ans = helper(stoneValue,0,dp);
        if(ans > 0) return "Alice";
        else if(ans < 0) return "Bob";
          return "Tie";
    }
};