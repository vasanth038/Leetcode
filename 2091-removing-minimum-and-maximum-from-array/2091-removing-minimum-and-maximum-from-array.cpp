class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 2) return n;

         int maxIdx = 0;
          int minIdx =  0 ;
            
           for(int i = 1;i<n;i++){
            if(nums[i] > nums[maxIdx]) maxIdx = i;
             if(nums[i] < nums[minIdx]) minIdx = i;
           }
          
             int leftMost = min(maxIdx,minIdx);
             int rightMost = max(maxIdx,minIdx);
             int ans = min(n-leftMost , rightMost+1);
              int x = min( maxIdx+1, n-maxIdx );
               int y = min( minIdx+1, n-minIdx );
            ans = min( ans, x+y);
          return ans;
    }
};