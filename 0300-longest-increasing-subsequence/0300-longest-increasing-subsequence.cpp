class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
         set<int>st;

         for(int i = 0;i<n;i++){
            int x = nums[i];

            auto it = st.lower_bound(x);
            if(it == st.end()) {
                st.insert(x);
            }
            else{
                 st.erase(it);
                 st.insert(x);
            }
         }

         return st.size();
    }
};