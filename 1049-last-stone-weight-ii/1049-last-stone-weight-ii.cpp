class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        //  a <= b <= c <= d,  d-(c-(b-a)) == d-c+b-a == d+b - (c+a);
        // find min diff or divide into eqaul sum

        int sum = accumulate(stones.begin(),stones.end(),0);

        int s = sum/2;
        int n = stones.size();

        vector<vector<bool>>dp(n,vector<bool>(s+1,false));

        dp[0][0]  = true;
        if(stones[0] <= s) dp[0][stones[0]] = true;

        for(int i = 1;i<n;i++){

            for(int j = 0;j<=s;j++){

                if(stones[i] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i]];
                else dp[i][j] = dp[i-1][j];
            }
        }

        int minD = 1e9;

        for(int j = s; j>=0;j--){

            if(dp[n-1][j]) {
                minD = sum-2*j;
                break;
            }
        }
        return minD;

    }
};