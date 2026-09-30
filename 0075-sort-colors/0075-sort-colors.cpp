class Solution {
   
public:
    void sortColors(vector<int>& arr) {
    
      
      int n = arr.size();

      int l = 0;
      int r = n-1;
      int m = 0;


      while(m <= r){

        if(arr[m] == 0){
             swap(arr[m],arr[l]);
             l++;
             m++;
        }
        else if(arr[m] == 1) m++;
        else {
            swap(arr[m],arr[r]);
            r--;
        }
         
      }
      
      

    
    }
};