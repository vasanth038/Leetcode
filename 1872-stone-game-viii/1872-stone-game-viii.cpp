class Solution { 
public:
    int stoneGameVIII(vector<int>& stones) {
       int n =  stones.size();
        
        vector<int>pref(n+1,0);

        for(int i = 0;i<n;i++) pref[i+1] = pref[i]+stones[i];
           
            int maxDiff = pref[n];

            for(int i = n-2; i>0;i--){

                maxDiff = max(maxDiff,pref[i+1]-maxDiff);
            }
          return maxDiff;
    }
};