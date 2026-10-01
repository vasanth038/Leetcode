class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (auto ch : s) {

            if (ch == ')' || ch == '}' || ch == ']') {
                char last = '(';
                if (ch == '}') last = '{';
                else if (ch == ']') last = '[';
                if (!st.empty() && st.top() == last) st.pop();
                else  return false ;
            }
            else st.push(ch);
        }
       
         return  st.empty() ? true : false ;
    }
};