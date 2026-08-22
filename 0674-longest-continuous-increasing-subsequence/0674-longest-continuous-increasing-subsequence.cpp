class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int len = 1;
        int maxLen = 1;
       int n = nums.size();
        for(int i = 1 ;i<n;i++){
            if(nums[i] > nums[i-1]){
                len ++;
                maxLen =max(len,maxLen);
            }
            else len = 1;
        }

        return maxLen;
    }
};