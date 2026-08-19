class Solution {
   
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
          
           unordered_map<int,set<int>>mpp;
           int m = reservedSeats.size();
           for(int i = 0;i<m;i++){
           int row =  reservedSeats[i][0];
           int seat = reservedSeats[i][1];
             if(seat >= 2 && seat <= 5)  mpp[row].insert(1);
             if(seat >= 4 && seat <= 7 )  mpp[row].insert(2);
             if(seat >= 6 && seat <= 9 )  mpp[row].insert(3);
           }
           int ans = 0;
           for(auto &[row , pos] : mpp){
              if(pos.size() == 3) continue;
                if(pos.size() == 0) ans+=2;
                else ans++;
           }

           int p = mpp.size();
           ans+=(n-p)*2;
           return ans;
    }
};