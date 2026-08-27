class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int>cnt(26,0);

        for(char ch : s) cnt[ch-'a']++;
        int n = target.size();
        for(int i = n - 1 ; i>=0;i--){

            vector<int>rem = cnt;
           bool ok = true;
            for(int j = 0 ; j<i;j++){
                
                int x = target[j]-'a';
                
                if(rem[x] == 0) {
                    ok = false;
                    break;
                }
                else rem[x]--;

            }

            if(!ok) continue;

            string ans = "";
            int x = target[i]-'a';

            for( int c = x+1; c < 26 ; c++ ){
                if(rem[c] == 0 ) continue;

                ans = target.substr(0,i);
                ans+= char('a'+c);
                   rem[c]--;
              for( int k = 0 ; k < 26 ; k++ ){
                ans.append(rem[k] , char('a'+k) );
                
            }

            return ans;
            }

         
        }
        return "";
        
    }
};