class Solution {
public:
    string reverseParentheses(string s) {


        string res;
         
         for(auto &ch :  s){
             
             if(ch != ')') res+=ch;
             else{

                 string cur = "";

                 while(!res.empty() && res.back() != '(' ){
                     cur+=res.back();
                     res.pop_back();
                 }
                 
                 if(!res.empty())  res.pop_back();
                 res+=cur;
                 
             }
         }

         return res;


        
        
    }
};