class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
     
       int n = nums1.size();
       bool paritySame = true;
      for(int i = 1;i<n;i++){
        
        if(nums1[0]%2 != nums1[i]%2 ){
            paritySame = false;
            break;
        }
       
      }

     int mini = *min_element(nums1.begin(),nums1.end());
      
      return (paritySame || mini%2 ) ? true : false ;
    }
};