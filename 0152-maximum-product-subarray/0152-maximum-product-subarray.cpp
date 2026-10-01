
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        
        int maxi = 1;
        int mini = 1;
        int maxAns = -1e9;
         int n = nums.size();
        for(int i = 0;i<n;i++){

            if(nums[i] < 0){
                 swap(maxi,mini);
            }
            
            maxi *= nums[i];
            mini *= nums[i];
              maxAns = max(maxAns , maxi);
            if(maxi <= 0) maxi = 1;   
            if(mini == 0) mini = 1;
             
        }

        return maxAns;
    }
};
