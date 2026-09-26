class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        map<string ,string>mpp;

        for(auto st : knowledge){
             mpp[st[0]] = st[1];
        }

        string res = "";

       int i = 0;
       int n = s.size();
       while(i < n ){

         if(s[i] == '('){
                i++;
                 string key = "";
             while( i < n && s[i] != ')'){
                key+=s[i];
                i++;
             }
             i++;
            
            if(mpp.count(key)){
                 res+=mpp[key];
            }
            else res+='?';

         }
         else {
            res+=s[i];
            i++;
         }
         
       }

       return res;
        
    }
};