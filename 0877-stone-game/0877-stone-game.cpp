class Solution {
    private:
      int helper(vector<int>&piles,int start,int end, vector<vector<int>>&dp){
         if(start > end ) return 0;
         if(dp[start][end] != -1) return dp[start][end];
         int first = piles[start]-helper(piles,start+1,end,dp);
          int last = piles[end]-helper(piles,start,end-1,dp);
          return dp[start][end] = max(first,last);
      }
public:
    bool stoneGame(vector<int>& piles) {
       return true;
    }
};