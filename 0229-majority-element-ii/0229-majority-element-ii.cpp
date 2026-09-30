class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {


        int n = nums.size();

        unordered_map<int,int>mpp;

        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }

        vector<int>ans;

        for(auto &[x,cnt] : mpp){

            if(cnt > n/3) ans.push_back(x);
        }

        return ans;
      
    }
};