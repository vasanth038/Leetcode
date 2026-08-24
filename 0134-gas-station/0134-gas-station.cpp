class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

       
           int idx = -1;
         for(int r = 0;r < 2*n ; r++){
             int c = gas[r%n]-cost[r%n] ;
             if(c < 0) continue;
              int gasLeft = 0; 
              int l = r;
              while( l < r+n){
                gasLeft += gas[l%n]-cost[l%n];
                if(gasLeft < 0) break;
                 l++;
              }
              if(l == r+n) {
                idx = r%n;
                break;
              }
            r = l;
         }

         return idx;

    }
};