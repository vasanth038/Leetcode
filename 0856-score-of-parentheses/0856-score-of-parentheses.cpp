class Solution {
public:
    int scoreOfParentheses(string s) {


        int n = s.size();
        int score = 0;
      
             stack<int>st;
          vector<pair<int,int>>last;
         for(int i = 0;i<n;i++){
          
           if(s[i] == '(') st.push(i);
           else{

                 int j = st.top();
                 st.pop();

                 if(i-j > 1) {
                       int l = last.size()-1;
                       int sum = 0;
                       while(!last.empty() && last[l].first > j){
                           sum+=last[l].second;
                           last.pop_back();
                           l--;
                       }
                       last.push_back({i,sum*2});
                 }
                 else last.push_back({i,1});
             
           }
              
         }

         int ans = 0;

         for(auto l : last){
              ans+=l.second;
         }
      
      return ans;
        
    }
};