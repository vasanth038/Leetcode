class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

      int n = cost.size();
       int prev2 = 0;
      int prev1 = cost[0];
      for(int i = 2;i<=n;i++){
         int cur = cost[i-1] + min(prev1,prev2);

         prev2 = prev1;
         prev1 = cur;
      }  

      return min(prev1,prev2);
    }
};