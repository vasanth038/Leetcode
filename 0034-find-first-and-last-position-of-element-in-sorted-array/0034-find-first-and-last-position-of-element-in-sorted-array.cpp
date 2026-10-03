class Solution {
   
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int f = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int l = upper_bound(nums.begin(),nums.end(),target)-nums.begin(); 
        if(f ==  n || nums[f] != target){
             return {-1,-1};
        }
         l--;
        return {f,l};
       
    }
};