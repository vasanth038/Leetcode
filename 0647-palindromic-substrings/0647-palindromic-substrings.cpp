class Solution {
public: 
       bool isPal(string s){
           int left = 0;
           int right = s.size()-1;
           while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
           }
           return true;
       }
        
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
         for(int i = 0 ;i < n;i++ ){
            for(int j = i ; j < n ; j++){
                if(isPal(s.substr(i,(j-i)+1))) count++;
              
            }
         }
         return count;
    }
};