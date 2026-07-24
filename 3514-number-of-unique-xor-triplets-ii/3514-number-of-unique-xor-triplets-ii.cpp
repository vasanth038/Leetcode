#include <bit>
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
         
         const int max = 2048;

         vector<bool>pair(max,false);
         vector<bool>triplet(max,false);
           int n = nums.size();
           for(int i = 0 ;i<n;i++){
            for(int j = i ;j<n;j++){
                pair[nums[i]^nums[j]] = true;
            }
           }
           for(int i = 0 ;i < max ;i++){
             if(!pair[i]) continue;
             for(int num : nums ) triplet[i^num]= true;
           }
           int count = 0;
           for( int i = 0 ; i<max;i++) if(triplet[i]) count++;

           return count;
    }
};