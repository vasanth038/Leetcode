class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       
       int n = nums.size();
    
       vector<int>ans(n);

       int i = 0;
       int j = 1;

       for(int x : nums){
         
          if(x < 0) {
            ans[j] = x;
            j+=2;
          }
          else {
            ans[i] = x;
            i+=2;
          }
       }

       return ans;
    
    }
};