class Solution {
public:
    int myAtoi(string s) {
    
       int n = s.size();
      int i = 0;
       while(i < n && s[i] == ' ') i++;

       int sign = 1;

       if(i < n && s[i] == '-') {
        sign = -1;
        i++;
       }
       else if(i < n && s[i] == '+') i++;
      
        long long ans = 0;
      while(i < n && s[i] >= '0' && s[i] <= '9'){
         ans = ans * 10 + s[i]-'0';
        if(ans*sign <= INT_MIN ) return INT_MIN;
        if(ans*sign >= INT_MAX) return INT_MAX;
         i++;
      }
       
       return sign*ans ;

    }
};