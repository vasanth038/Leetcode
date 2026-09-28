class Solution {
public:
    int majorityElement(vector<int>& nums) {
    
        int maj = nums[0];
        int len = 1;
        int n = nums.size();

        for(int i = 1;i<n;i++){
            if(maj != nums[i]) len--;
            else len++;
            if(len == 0){
                 maj = nums[i];
                 len++;
            } 
        }

        return maj;
     
    }
};