class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>ans;
        long long mod=1e9+7;
        int n = s.size();
        vector<long long>pow(n+1);
        pow[0] = 1;
        for(int i = 1 ; i<=n;i++){
          pow[i] = (pow[i-1]*10 )%mod;
        }

        vector<pair<long long , long long> > a(n);
        vector<long long>pre(n);
          int count = 0;
          long long num = 0;
          long long sum = 0;
        for(int i = 0 ; i<n;i++){
            int x = s[i]-'0';
            if(x != 0){
             count++;
          num = (1ll*num*10)%mod + x ;
            }
            a[i] = {num ,count};
            pre[i] = sum+=x;
        }
         
        
        for(int q = 0 ;q<queries.size();q++){

            long long sum = 0;
            long long num = 0;
            int start = queries[q][0];
            int end = queries[q][1];
            if(start > 0){
                 num = a[end].first ;
                   int len = a[end].second - a[start-1].second;
                 long long tominus = (a[start-1].first * pow[len] )%mod;
                 num = (num-tominus+mod)%mod;
                 sum = pre[end]-pre[start-1];
               
            }
            else {
                num = a[end].first;
                sum = pre[end];
            }
            int val = (1ll*num*sum)%mod;
            ans.push_back(val);

        }

          return ans;
        
    }
};