class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        int len = n+1;
        string res = "";
        int ones = 0;

        int l = 0;

        for(int i = 0;i<n;i++){

        if(s[i] == '1') ones++;
         while(ones > k   && l <= i){
            if(s[l] == '1' ) ones--;
            l++;
         }
          while( s[l] == '0' && l <= i){
                l++;
             }

         if(ones == k){
           
            int cur_len = i-l+1;
             if(cur_len == len){
                 string cur = s.substr(l,len);
                 if(cur < res) res = cur;
            }
            if(cur_len  < len){
                len = cur_len;
                res = s.substr(l,len);
            }
           
         }
        }

        return res;

    }
};