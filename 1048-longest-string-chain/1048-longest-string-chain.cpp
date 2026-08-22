class Solution {

     private:    
   static bool comp (const string&a ,const string&b ){
      return a.size() < b.size();
   }
    bool isok(string &a , string &b){
        int n = a.size();
        int m = b.size();
        if(m-n != 1 ) return false;
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(a[i] == b[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
           
        }

        return  i == n;

    }
public:
    int longestStrChain(vector<string>& words) {
       sort(words.begin(),words.end(),comp); 
          int n = words.size();
         vector<int>dp(n,1);
          for(int i = 0;i <n;i++){

            for(int p = 0;p < i;p++){
                if(isok(words[p],words[i])){
                    dp[i] = max(dp[i],dp[p]+1);
                  
                }
            }
          }

          return *max_element(dp.begin(),dp.end());

    }
};