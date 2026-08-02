class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
              int x = 0;
               int y  = 0;
             for(int j = i;j<n;j++){
                if(nums[j] & 1) y++;
                else x++;
               if(x*b <= y*a) count++;
             }
        }
        return count;
    }
};