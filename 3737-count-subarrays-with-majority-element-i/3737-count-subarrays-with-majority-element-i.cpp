class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
         int n = nums.size();
         int count = 0 ;
         for(int i = 0 ; i < n ; i++){
            int tar_cnt = 0;
            for(int j = i ; j<n;j++){
                if(nums[j] == target) tar_cnt++;
                if(2*tar_cnt >((j-i)+1) ) count++;
            }
         }
         return count;
    }
};