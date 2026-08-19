class Solution {
     private:
       static bool comp(const vector<int>&a ,const vector<int>&b ){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
       }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        sort(reservedSeats.begin(),reservedSeats.end(),comp);

        int p = 0;
        int ans = 0;
         int m = reservedSeats.size();
        int i = 0;
        while(i < m){
             bool a = true,b= true,c = true;
               int j = i;
            while( j < m && reservedSeats[i][0] == reservedSeats[j][0]){
                if(reservedSeats[j][1]  >= 2 && reservedSeats[j][1]  <= 5 ) a = false;
                if(reservedSeats[j][1]  >= 4 && reservedSeats[j][1]  <= 7 ) b = false;
                 if(reservedSeats[j][1]  >= 6 && reservedSeats[j][1]  <= 9 ) c = false;
                 j++;
            } 
            p++;
            if(a) ans++;
             if( !a && b ) ans++;
             else if( c) ans++;
            i = j ; 
        }
       ans+=(n-p)*2;
        return ans;
    }
};