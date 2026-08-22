class Solution {
public:
      
       int h (string &s , int i){
            int n = s.size();
           int l = 0;
           int r = n-1;
           int cnt = 0;
           while(l < r){
               
               int x = s[(l+i)%n]-'a';
               int y = s[(r+i)%n]-'a';
               l++;
               r--;
              if(x > y) swap(x,y);

              int sm = abs(x-y);
               sm = min(sm , abs(x-y+26));
               cnt+=sm;
            
            }
            return cnt;

       }
    int minOperations(string s) {
        int n = s.size();
        int ans = 1e9;
        for(int i = 0;i<n;i++){
             
             ans = min(ans,h(s,i)+i);
             
        }

        return ans;
    }
};