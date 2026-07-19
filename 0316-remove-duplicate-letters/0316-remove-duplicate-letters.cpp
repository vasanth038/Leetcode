class Solution {
public:
    string removeDuplicateLetters(string s) {
         string st = "";
        vector<int>freq(26,0);
        for(char ch : s) freq[ch-'a']++;
        vector<int>seen(26,0);
        for(char ch : s){
             freq[ch-'a']--;

             if(seen[ch-'a']) continue;
             while(!st.empty() && st.back() > ch && freq[st.back()-'a'] > 0){
                seen[st.back()-'a'] = 0 ;
                st.pop_back();
             }
          seen[ch-'a'] = 1;
             st.push_back(ch);
        }
        return st; 
    }
};