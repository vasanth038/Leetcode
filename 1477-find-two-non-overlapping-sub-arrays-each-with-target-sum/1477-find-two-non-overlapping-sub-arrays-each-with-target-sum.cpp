class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int l = 0;
        int sum = 0;
        int n = arr.size();
        vector<int>min_len(n,1e9);
       int ans = 1e9 ;
       int  best = 1e9;

        for(int i = 0;i<n;i++){

             sum+=arr[i];
            while( l <= i  && sum > target){
                sum-=arr[l];
                l++;
            }

         if(sum == target){

            int cur = i-l+1;

            if(l > 0 && min_len[l-1] != 1e9){
                ans =  min(ans,cur+min_len[l-1]);
            }

            best = min(cur,best);
            
          }

          min_len[i] = best;
        }

        if(ans >= 1e9 ) return -1;

        return ans;
        
    }
};