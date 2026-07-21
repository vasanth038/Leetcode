class Solution {
    private:
      int check(string &s , int l , int r , int cnt ){
           l--;
           r++;
           cnt -= (r-l-1);
           int n = s.size();
           bool left = false;
           bool right = false;
           if(l >= 0 && r < n && s[l] == '0' && s[r] == '0'){
            while(l >= 0 && s[l] == '0' ) {
            left = true;
            l--;
          }
          while(r < n && s[r] == '0') {
            right = true;
            r++;
          }
           }

          if(left && right){
               while(l >= 0 && s[l] == '1' ) {
            l--;
            cnt--;
           
          }
          while(r < n && s[r] == '1') {
            r++;
            cnt--;
          }
           
          
        
          }
          return (r-l-1)+cnt;


      }
public:
    int maxActiveSectionsAfterTrade(string s) {

       int n = s.size();
        int cnt = 0;
        for(char ch : s) {
            if(ch == '1') cnt++;
        }
        int max_len = cnt ;
        for(int i = 0 ;i<n;){
            if(s[i] == '1' ){
                  int l = i;
                while(s[i] == '1'){
                    i++;
                } 
                 max_len = max(max_len , check(s,l , i-1 , cnt) );
            }
            else i++;
        } 
        return max_len;
    }
};