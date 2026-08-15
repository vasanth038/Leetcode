class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        sort(nums.rbegin(),nums.rend());
       if(nums[0] == 0) return 0;
        
        int X = 0;
        for(int num : nums){
             X^=num;
        }
        int n =nums.size();
        if(X) return n;

        return n-1;
    }
};