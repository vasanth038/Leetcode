class Solution {
public:
    int scoreOfParentheses(string s) {    
          stack<int>st;
         for(auto ch : s ){
          
           if(ch == '(') st.push(-1);
           else{
                   int last = 0;
                  while( st.top() != -1){
                      last+=st.top();
                      st.pop();
                  }
                      st.pop();
                   if(last !=  0) st.push(last*2);
                   else st.push(1);          
             
           }
              
         }
              int score = 0;
              while(!st.empty()){
                score+=st.top();
                st.pop();
              }
      
      return score;
        
    }
};