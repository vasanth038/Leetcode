class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>next(n+1,0);
         for(int i = n-1;i >=0;i--){
                vector<int>cur(n+1,0);
             for(int p = -1;p<i;p++){
                if(p == -1 || nums[i] > nums[p]){
                     cur[p+1] = max(1+next[i+1],cur[p+1]);
                }
                cur[p+1] = max(next[p+1] ,cur[p+1]);
             }
             swap(next,cur);
         }

         return next[0];


        
    }
};