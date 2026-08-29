class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int>sorted = nums;
        sort(sorted.begin(),sorted.end());

        unordered_map<int,vector<int>>group;
        unordered_map<int,int>grpId;
        int id = 0;
         group[id].push_back(sorted[0]);
         grpId[sorted[0]] = 0;
        for(int i = 1;i<n;i++){
            if(sorted[i] - sorted[i-1] > limit) id++;
            group[id].push_back(sorted[i]);
             grpId[sorted[i]] = id;
        }

        vector<int>pos(id+1);
        for(int i = 0;i<=id;i++){
            pos[i] = 0;
        }

        for(int i = 0;i<n;i++){
            int id = grpId[nums[i]];

            nums[i] = group[id][pos[id]];
            pos[id]++;
        }

  return nums;
    }
};