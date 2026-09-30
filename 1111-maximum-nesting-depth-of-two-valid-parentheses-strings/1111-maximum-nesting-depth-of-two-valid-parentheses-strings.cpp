class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {


            int n = seq.size();


            int level = 0;
             vector<int>ans(n,0);
            for(int i = 0;i<n;i++){

                if(seq[i] == '(') {
                    level++;
                    if(level%2) ans[i] = 1;
                }
                else {
                     if(level%2) ans[i] = 1;
                     level--;
                }
                 
            }

            return ans;
        
    }
};