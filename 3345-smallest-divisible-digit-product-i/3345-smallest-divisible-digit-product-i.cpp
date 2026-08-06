class Solution {
public:
    int smallestNumber(int n, int t) {
         
         int x = n; 
         int p = 1;
         while(x > 0){
             int rem = x%10;
              p*=rem;
              x/=10;
         }
         if(p%t == 0) return n;
         int rem = n%10;
            p/=rem;
          for(int i = rem ; i<10;i++){
             if((p*i)%t == 0) {
                return n+(i-rem);
             }
          }
           
          return n + (10-rem);
    }
};