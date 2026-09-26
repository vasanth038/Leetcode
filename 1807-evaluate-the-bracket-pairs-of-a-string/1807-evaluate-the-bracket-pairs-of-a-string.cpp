class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string ,string>mpp;

        for(auto& st : knowledge){
             mpp[st[0]] = st[1];
        }

        string res = "";
       int n = s.size();
       
       for(int i = 0;i<n;i++){
           
           if(s[i] == '('){

             int j = s.find(")" , i+1);
             auto key = s.substr(i+1 , j-i-1);
             res+=  mpp.count(key) ? mpp[key] : "?" ;
              i = j ;
           }
           else res+=s[i];
         
       }

       return res;
        
    }
};