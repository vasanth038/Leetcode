class Solution {
public:
    int numberOfSubstrings(string s) {
      vector<int>a(3,0);
       int count = 0;
        int left = 0;
         int n = s.size();
        for(int right = 0 ;right < n;right++){
            a[s[right]-'a']++;
            while(left < n && a[0] > 0 && a[1] > 0 && a[2] > 0){
                    count+=(n-right);
                a[s[left]-'a']--;
                left++; 
            
            }
        }
        return count;
       
    }
};