class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>mpp(26,0);
        for(char ch : t) mpp[ch-'a']++;
        for(char ch : s) mpp[ch-'a']--;
        for(int i = 0 ;i < 26;i++){
            if(mpp[i] > 0) return i+'a' ;
        }

      return 'z' ;
    }
};