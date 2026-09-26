class Solution {
public: 
       static bool comp(const vector<int>&a , const vector<int>&b ){
          if(a[0] == b[0]) return a[1] < b[1];
           return a[0] < b[0];
       }

        int helper(vector<vector<int>>& intervals , int l ,int r ,int end){
             int p = -1;
              while(l <= r){
                  int m = l +(r-l)/2;
                if(intervals[m][0] <= end ){
                     p = m ; 
                     l = m+1;
                }
                else  r = m-1;
                 
              }

            return p;
        }
        
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        
         sort(intervals.begin(),intervals.end(), comp );


         long long pairs = 0 ;
         int n = intervals.size();
         for(int i = 0;i<n;i++){

             int start = intervals[i][0];
             int end = intervals[i][1];
            int p =  helper(intervals , i+1 , n-1 , end);

             if(p != -1 ){

                 pairs+= p - i  ;
                 
             }
             
         }
         

         return pairs;


    }
};