class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
         int n = word1.size();
         int m = word2.size();
        vector<int>last(m,-1);
         int j = m-1;
        for(int i = n-1;i>=0 && j >= 0;i--){
           if(word2[j] == word1[i]){
            last[j] = i;
            j--;
           }
        }

        vector<int>ans(m);
          j = 0;
          bool skip = true;
        for(int i = 0;i<n && j < m;i++){

            if(word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }
            else if(skip && (j == m-1 || i < last[j+1])){
                 ans[j] = i;
                 skip = false;
                 j++;
            }
        }
        if(j == m) return ans;

        return {};

    }
};