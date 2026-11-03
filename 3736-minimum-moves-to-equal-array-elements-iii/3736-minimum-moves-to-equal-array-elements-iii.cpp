class Solution {
public:
    int minMoves(vector<int>& nums) {
          
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int moves =  n * maxi - accumulate(nums.begin(), nums.end(), 0);

        return moves;
    }
};