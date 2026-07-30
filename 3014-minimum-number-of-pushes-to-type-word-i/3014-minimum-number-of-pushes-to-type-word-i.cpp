class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int k = 1;
        int ans = 0;
         while(n > 0 ){
              if(n <= 8){
                ans+=(n*k);
                break;
              }
              ans+=8*k;
              n-=8;
              k++;

         }
         return ans;
    }
};