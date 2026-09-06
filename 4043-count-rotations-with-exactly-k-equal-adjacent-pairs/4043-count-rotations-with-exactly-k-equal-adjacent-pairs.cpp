class Solution {
public:
    int countRotations(string s, int k) {

        int n = s.size();

        int cnt = 0;

        for(int i =0 ;i<n-1;i++){
            if(s[i] == s[i+1])cnt++;
        }
         int ans = 0;
         if(cnt == k) ans++;
          int l = 0;
          int r = n-1;
       for(int i = 1;i<n;i++){
           
         if(s[l] == s[(l+1)%n] ){
             cnt--;
         }
         if(s[l] == s[r]) cnt++;
         
         if(cnt == k) ans++;

         l = (l+1)%n;
         r = (r+1)%n;   
       }

       return ans;
        
    }
};