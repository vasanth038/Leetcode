class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int X = 0;
        int cnt0 = 0;
        for(int num : nums){
             X^=num;
             if(num == 0) cnt0++;
        }
        int n =nums.size();
       if(cnt0 == n) return 0;
        if(X) return n;
        return n-1;
    }
};