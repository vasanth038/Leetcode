class Solution {
public:
    int maxDepth(string s) {
    
      int maxD = 0;
      int depth = 0;

      for(auto ch : s){
         
         if(ch == '(') depth++;
         else if(ch == ')') depth--;
         maxD = max(maxD,depth);
      }

      return maxD;
    }
};