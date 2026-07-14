class Solution {
      static const int MOD = 1e9 + 7;
    private:
     int helper(vector<int>&nums , vector<vector<vector<int>>>&dp , int i , int g1 , int g2  ){
         if(i == nums.size() ) {
            return (g1 == g2 && g1 != 0 )  ;
         
         }
        if(dp[i][g1][g2] != -1) {
            return dp[i][g1][g2] ; 
        }
        int new_g1 = gcd(nums[i] , g1) ;
        int new_g2 = gcd(nums[i] , g2) ;
    int t1 =  helper(nums , dp , i+1 ,new_g1 , g2 ) ;
    int t2  =   helper(nums , dp , i+1 ,g1 , new_g2) ; 
      int skip  =   helper(nums , dp , i+1 ,g1 , g2 ) ;

      return dp[i][g1][g2] = (((t1+t2)%MOD)+skip)%MOD ;
          
     }
public:
    int subsequencePairCount(vector<int>& nums) {
         
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(mx + 1, vector<int>(mx + 1, -1)));

       int count   =  helper(nums,dp , 0 ,0 , 0);
         return count ;

    }
};