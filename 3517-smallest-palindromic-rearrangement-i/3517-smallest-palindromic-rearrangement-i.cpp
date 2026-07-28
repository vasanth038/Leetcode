class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>freq(26,0);
        string res(n,' ');
       for(int i = 0;i<n/2;i++){
           freq[s[i]-'a']++;
       }
         int j = 0;
         for(int i = 0;i<26;i++){
           while(freq[i] > 0){
              res[j] = 'a'+i;
              res[n-1-j] = 'a'+i;
               j++;
              freq[i]--;
           }
       }
       if(n%2 == 1) {
         int k = (n+1)/2;
        res[k-1] = s[k-1] ;
       }
       return res;
       
    }
};