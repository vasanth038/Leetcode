class Solution {
public:
    int maxDepth(string s) {
        
        int maxi = 0;
        int level =0;

        for(auto &c : s){
             if(c == '(') level++;
             else if(c == ')') level--;
             maxi = max(maxi , level);
        }

        return maxi;
    }
};