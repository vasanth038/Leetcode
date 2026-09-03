class Solution {
    private:
     static bool comp(const vector<int>&a , const vector<int>&b){
         if(a[1] == b[1]) return a[0] < b[0];
         return a[1] < b[1];
     }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
      sort(pairs.begin(),pairs.end(),comp);  

      int n = pairs.size();
      int end = pairs[0][1];
      int len = 1;

      for(int i = 1;i<n;i++){
        if(end < pairs[i][0]){
            len++;
            end = pairs[i][1];
        }
      }
      return len;
    }
};