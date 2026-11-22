class Solution {
public:
    bool checkString(string s) {


        bool present = false;

        for(auto ch : s){
            if(ch == 'b') present = true;
            if(present && ch == 'a') return false;
        }
        return true;
        
    }
};