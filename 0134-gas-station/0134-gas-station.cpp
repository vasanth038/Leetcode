class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
            int n = gas.size();
           int total = 0;
           int current = 0;
           int idx = 0;
         for(int r = 0;r < n; r++){
             int net = gas[r]-cost[r] ;
             total +=net;
             current+= net;
             if(current < 0){
                current = 0;
                idx = r+1;
             }
             
         }

         return (total < 0 ?  -1 : idx );

    }
};