class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        //  a <= b <= c <= d,  d-(c-(b-a)) == d-c+b-a == d+b - (c+a);
        // find min diff or divide into eqaul sum

        int sum = accumulate(stones.begin(),stones.end(),0);

        int s = sum/2;
        int n = stones.size();

        vector<bool>prev(s+1,false);

        prev[0]  = true;
        if(stones[0] <= s) prev[stones[0]] = true;

        for(int i = 1;i<n;i++){
           vector<bool>cur(s+1,false);
            for(int j = 0;j<=s;j++){

                if(stones[i] <= j) cur[j] = prev[j] || prev[j-stones[i]];
                else cur[j] = prev[j];
            }
            swap(cur,prev);
        }

        int minD = 1e9;

        for(int j = s; j>=0;j--){

            if(prev[j]) {
                minD = sum-2*j;
                break;
            }
        }
        return minD;

    }
};