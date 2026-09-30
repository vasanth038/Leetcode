class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

         sort(nums.begin(),nums.end());
        int n = nums.size();
  
        vector<vector<int>>ans;
          
        for(int i = 0;i<n;){
             
              unordered_map<int,int>mpp;
              bool found = false;
            for(int j = i+1;j<n;j++){
                int req = -nums[i]-nums[j];
                if(mpp.count(req)){
                    vector<int>cur = {nums[i],nums[j],req} ;
                     if(ans.empty() || ans.back() != cur ) ans.push_back(cur);
                     found = true;
                }
              mpp[nums[j]]++;
            }
             int cur = nums[i]; 
            while(i < n && nums[i] == cur) i++;
             
        }

        return ans;
       
    }
};