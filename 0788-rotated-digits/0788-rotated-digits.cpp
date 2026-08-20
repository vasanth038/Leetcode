class Solution {
     private:
      int helper(int n ){
        bool all = true ;
       while(n){
         int r = n%10;
         if(r == 4 || r == 7 || r == 3) return 0;
         if(r != 0 && r != 1 && r != 8)  all = false;
         n = n/10;
       }
       if(!all) return 1;
       return 0;
     }
      

public:  
    int rotatedDigits(int n) {
         
         int count = 0;
         for(int i = 1; i <= n;i++){
            count+=helper(i);
         }
         return count;
    }
};