class Solution {
public:
    int distinctSubseqII(string s) {
         long long mod = 1e9+7;
        vector<int>dp(26,0);

        for(auto ch : s){
             
             long long totalbefore = 0;
             for(int i : dp) totalbefore = (totalbefore+i)%mod;
             dp[ch-'a'] = (totalbefore+1)%mod; 
        }

          
             long long total = 0;
             for(int i : dp) total = (total+i)%mod;

              return total;
    }
};