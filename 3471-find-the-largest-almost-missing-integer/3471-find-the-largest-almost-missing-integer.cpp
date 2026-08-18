class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k ) return *max_element(nums.begin(),nums.end());
        vector<int>mpp(51,0);
        for(int i = 0;i<n;i++){
                mpp[nums[i]]++;
        } 
     if(k > 1 ){
         int maxi = -1;
        int cnt = mpp[nums[0]];
         if(cnt == 1){
            maxi = max(maxi,nums[0]);
         }
        int cnt2 = mpp[nums[n-1]];
         if(cnt2 == 1){
            maxi = max(maxi,nums[n-1]);
         }
     
      return maxi;
     }
     int maxi = -1;
     for(int i = 0;i<51;i++){
        int cnt = mpp[i];
         if(cnt == 1){
            maxi = max(maxi,i);
         }
     }
        return maxi;
     
    }
};