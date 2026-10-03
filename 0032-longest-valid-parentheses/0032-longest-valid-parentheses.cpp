class Solution {
public:
    int longestValidParentheses(string s) {


        int n = s.size();
        stack<int>st;
        st.push(-1);

        int len = 0;
        for(int i = 0;i<n;i++){

            if(s[i] == ')' && st.top() != -1 && s[st.top()] == '('){ 
                 st.pop();
                 len = max(len,i-st.top());
            }
            else st.push(i);
             
        }

        return len;
    
    }
};