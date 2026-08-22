class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>left(n,0);
        vector<int>right(n,0);

        for(int i = 0;i<n;i++){

            for(int p = 0;p<i;p++){
                if(nums[i] > nums[p]){
                    left[i] = max(left[i],left[p]+1);
                }
            }
        }

        for(int i = n-1;i>=0;i--){

            for(int next = n-1;next>i;next--){
                if(nums[i] > nums[next]){
                    right[i] = max(right[i],right[next]+1);
                }
            }
        }

        int maxLen = 0;
        for(int i = 0;i<n;i++){

            if(left[i] > 0 && right[i] > 0){
                maxLen = max(maxLen,left[i]+right[i]+1);
            }
        }

        return n-maxLen;
    }
};