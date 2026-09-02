class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();

        vector<vector<int>>ans;
           int i = 0;
         while(i < n){
              if(intervals[i][1] >= newInterval[0]) break;
              ans.push_back({intervals[i][0] , intervals[i][1] }) ;
              i++;
        }
           int start = newInterval[0];
           int end = newInterval[1] ;
         while(i < n){
              if(max(intervals[i][0] ,start) <= min ( intervals[i][1] ,end)) {
                 start = min(start ,intervals[i][0] );
                 end = max(end, intervals[i][1] ) ;
              }
              else break;
              i++;
        }

        ans.push_back({start,end});
          while(i < n){
              ans.push_back({intervals[i][0] , intervals[i][1] }) ;
              i++;
        }

      return ans;

     

    }
};