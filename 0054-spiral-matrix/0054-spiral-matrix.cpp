class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {


        int n = a.size();
        int m = a[0].size();

        int left = 0;
        int right = m-1;
        int up = 0;
        int down = n-1;

        vector<int>ans;

      while(left <= right && up <= down){
        
          for(int i = left;i <= right;i++){
              ans.push_back(a[up][i]);
          }
           
            up++;
           for(int i = up ; i <= down ;i++){
            ans.push_back(a[i][right]);
           }
           right--;
            
           if(down >= up ){
            for(int i = right ;i >= left ;i--){
              ans.push_back(a[down][i]);
              }
            down--;

           } 
            
            
            if(left <= right ) {
                for(int i = down ; i >= up  ;i--){
              ans.push_back(a[i][left]);
             }
             left++;
            }
    
      }


        return ans;
        
       
    }
};