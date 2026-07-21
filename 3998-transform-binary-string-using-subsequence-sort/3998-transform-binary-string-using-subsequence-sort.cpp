class Solution {
     private: 
      bool check(string s , string str , int cnt0 , int cnt1){
          int c0 = 0;
          int c1 = 0;
          for(char ch : str){
             if(ch == '0') c0++;
             if(ch == '1') c1++;
          }
          if(cnt0 < c0 || cnt1 < c1 ) return false;
          int zeros = cnt0-c0;
          for(int i = 0 ;i < str.size();i++){
             
            if(str[i] == '?' ) {
              if(zeros > 0)  {
                str[i] = '0';
                zeros--;
            }
            else str[i] = '1' ;
            }
          } 
          int s_cnt = 0;
          int str_cnt = 0;
           for(int i = 0;i<str.size();i++){
              if(s[i] == '0') s_cnt++;
              if(str[i] == '0') str_cnt++;
              if(s_cnt > str_cnt) return false;
           }
           return true;
      }
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
       vector<bool>ans;
         int cnt0 = 0;
          int cnt1 = 0;
          for(char ch : s){
             if(ch == '0') cnt0++;
             if(ch == '1') cnt1++;
          }
        for(auto &str : strs){
             
           ans.push_back(check(s , str , cnt0 , cnt1) );
        }
        return ans ;
    }
};