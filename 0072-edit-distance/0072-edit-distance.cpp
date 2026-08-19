class Solution {
      private:
        
        int helper(string & word1,string&word2 , int i , int j,  vector<vector<int>>&dp){
          if(j < 0  ) return i+1;
          if(i < 0) return j+1;
           if(dp[i][j] != -1) return dp[i][j];
           if(word1[i] == word2[j]) return helper(word1,word2,i-1,j-1,dp);
              
                int rp = 1+helper(word1,word2,i-1,j-1,dp);
                int d = 1+helper(word1,word2,i-1,j,dp);
                int in = 1+helper(word1,word2,i,j-1,dp);
           return  dp[i][j] = min({rp,d,in});
        }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
         vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(word1,word2,n-1,m-1,dp); 
    }
};