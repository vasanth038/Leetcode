class Solution {
  
public:
    int longestCommonSubsequence(string text1, string text2) {
         int n = text1.size();
         int m = text2.size();
          vector<int>prev(m+1,0);
          for(int i = 1;i<=n;i++){
             vector<int>cur(m+1,0);
             for(int j = 1;j<=m;j++){
                int match = 0;
                int notmatch = max(prev[j] , cur[j-1]);
                if(text1[i-1] == text2[j-1]) match = 1+prev[j-1];

               cur[j] = max(match, notmatch);
             }
             prev = cur;
          }


         return prev[m];  
    }
};