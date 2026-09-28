class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       
       int n = nums.size();

       stack<int>pos;
       stack<int>neg;

       for(auto i : nums){
          if(i < 0) neg.push(i);
          else pos.push(i);
       }

        vector<int>ans(n);
        for(int i = n-1;i>=0;i--){

            if(i%2) {
               ans[i] = neg.top();
               neg.pop();
            }
            else{
            ans[i] = pos.top() ;
               pos.pop();
            }
        }


     return ans;

    }
};