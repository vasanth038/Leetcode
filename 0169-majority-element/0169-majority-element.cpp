class Solution {
public:
    int majorityElement(vector<int>& nums) {

       int majorElement = 0 ;
       int cnt = 0; 

       for(int  n : nums){
         if(cnt == 0){
             majorElement = n;
         }
         if(majorElement != n) cnt--;
         else cnt++;
        
       }

       return majorElement;
    }
};