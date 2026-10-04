class Solution {

public:
         bool helper(string &s , int i , int level, vector<vector<int>>&dp){
               int n  = s.size();
            if( i >= n ){
              if(level == 0) return true;
              else return false; 
            }
              
              if(level < 0 ) return false;
              if(dp[i][level] != -1) return dp[i][level];
              bool ans = false;
             if(s[i] == '*'){
                 for(int j = -1 ; j<2;j++){
                 ans = ans | helper(s,i+1,level+j,dp);
                }

             }
             else  if(s[i] == '(') ans = helper(s,i+1,level+1,dp);
             else   ans = helper(s,i+1,level-1,dp);
             
           return dp[i][level] = ans;

         }


    bool checkValidString(string s) {
          int n = s.size();
         vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(s,0,0,dp);
        
    }
};